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

    printf("%d\n", getrdquality(type, atoi(argv[2])));
    freenetwork();

    return 0;
}