#ifndef STAT_H
#define STAT_H

#include "parser.h"

#include <stdlib.h>

typedef enum {
    NO_ERROR = 0,
    ERR_INV_DIM = -1,
} error_e;

error_e initsum(matrix_t* obj);

#endif
