#ifndef STAT_H
#define STAT_H

#include "parser.h"

#include <stdlib.h>

typedef enum {
    NO_ERROR = 0,
    ERR_INV_DIM = -1,
    ERR_MMAP = -2,
    ERR_FORK = -3,
    ERR_PROC_TERM = -4,
} error_e;

error_e initsum(matrix_t* obj);

#endif
