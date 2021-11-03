#include "paral.h"

#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define unlikely(expr) __builtin_expect(!!(expr), 0)
#define likely(expr) __builtin_expect(!!(expr), 1)

error_e initsum(matrix_t* obj)
{
    int* tsum = (int*)mmap(NULL, (obj->dim * 2 - 1) * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (unlikely(tsum == MAP_FAILED))
        return ERR_MMAP;

    if (obj->dim == 1) {
        tsum[0] = obj->matrix[0][0];
        obj->dsum = tsum;
        return NO_ERROR;
    }

    pid_t* pids = (pid_t*)mmap(NULL, (obj->dim - 1) * sizeof(pid_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    size_t* pidnum = (size_t*)mmap(NULL, sizeof(size_t), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (unlikely(pids == MAP_FAILED || pidnum == MAP_FAILED))
        return ERR_MMAP;

    pid_t mainpid = fork();
    if (unlikely(mainpid == BAD_VAL))
        return ERR_FORK;
    if (mainpid) {
        // main diagonal
        for (size_t i = 0; i < obj->dim; ++i)
            tsum[obj->dim - 1] += obj->matrix[i][i];

        if (wait(0) == BAD_VAL)
            return ERR_PROC_TERM;
    } else {
        // diagonals with shifts
        size_t shift = 1;
        while (shift < obj->dim) {
            pid_t pid = fork();
            if (pid) {
                if (shift + 1 < obj->dim) {
                    ++shift;
                    continue;
                }

                for (size_t i = 0; i < obj->dim - 1; ++i) {
                    int wstatus;
                    waitpid(pids[i], &wstatus, 0);
                    if (unlikely(!WIFEXITED(wstatus)))
                        return ERR_PROC_TERM;
                }

                exit(0);
            } else {
                pids[*pidnum] = pid;
                *pidnum += 1;

                pid_t tpid = fork();
                if (unlikely(tpid == BAD_VAL))
                    return ERR_PROC_TERM;
                if (tpid) {
                    for (size_t i = 0; i + shift < obj->dim; ++i)
                        tsum[(obj->dim - 1) + shift] += obj->matrix[i][i + shift];

                    if (unlikely(wait(0) == BAD_VAL))
                        return ERR_PROC_TERM;

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

    if (unlikely(munmap(pids, (obj->dim - 1) * sizeof(pid_t)) == BAD_VAL || munmap(pidnum, sizeof(size_t)) == BAD_VAL))
        return ERR_MMAP;

    return NO_ERROR;
}
