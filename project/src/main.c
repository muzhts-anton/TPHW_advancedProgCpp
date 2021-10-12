#include <stdlib.h>

#include "rderrors.h"
#include "rdnetwork.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
        return err_input(argv[0]);

    addnetwork();

    rdtype_e type = gettype(argv[1]);
    if (type == ERROR)
        return err_input(argv[0]);

    switch(getrdquality(type, atoi(argv[2]))) {
        case TERRIBLE: printf("TERRIBLE\n"); break;
        case BAD: printf("BAD\n"); break;
        case NORM: printf("NORM\n"); break;
        case GOOD: printf("GOOD\n"); break;
        case GREAT: printf("GREAT\n"); break;
        default: printf("ERROR\n");
    }
    freenetwork();

    return 0;
}