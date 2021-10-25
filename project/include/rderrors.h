#ifndef RDERRORS_H
#define RDERRORS_H

#include <stdio.h>

#define ERR_INPUT -1

extern inline int err_input(char progname[])
{
    printf("Usage: %s _road-type_ _number-of-lanes_\n", progname);
    return ERR_INPUT;
}

#endif