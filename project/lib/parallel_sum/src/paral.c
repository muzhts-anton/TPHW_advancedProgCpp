#include "paral.h"

#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

error_e initsum(matrix_t* obj)
{
    int* tsum = (int*)mmap(NULL, (obj->dim * 2 - 1) * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (tsum == MAP_FAILED)
        return ERR_MMAP;

    if (obj->dim == 1) {
        tsum[0] = obj->matrix[0][0];
        obj->dsum = tsum;
        return NO_ERROR;
    }

    pid_t* pids = (pid_t*)mmap(NULL, (obj->dim - 1) * sizeof(pid_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    size_t* pidnum = (size_t*)mmap(NULL, sizeof(size_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (pids == MAP_FAILED || pidnum == MAP_FAILED)
        return ERR_MMAP; // TODO:handle the errors

    if (fork()) {
        // mid main
        for (size_t i = 0; i < obj->dim; ++i)
            tsum[obj->dim - 1] += obj->matrix[i][i];
        wait(0);
    } else {
        size_t shift = 1;
        while (shift < obj->dim) {
            pid_t pid = fork();
            if (pid) {
                if (shift + 1 < obj->dim) {
                    ++shift;
                    continue;
                }

                for (size_t i = 0; i < obj->dim - 1; ++i)
                    waitpid(pids[i], NULL, 0);
                exit(0);
            } else {
                pids[*pidnum] = pid;
                *pidnum += 1;
                if (fork()) {
                    for (size_t i = 0; i + shift < obj->dim; ++i)
                        tsum[(obj->dim - 1) + shift] += obj->matrix[i][i + shift];

                    wait(0);
                    exit(0);
                } else {
                    for (size_t i = 0; i + shift < obj->dim; ++i)
                        tsum[(obj->dim - 1) - shift] += obj->matrix[i + shift][i];

                    exit(0);
                }
            }
        }
    }

    obj->dsum = tsum;

    munmap(pids, (obj->dim - 1) * sizeof(pid_t));
    munmap(pidnum, sizeof(size_t));

    return 0;
}
