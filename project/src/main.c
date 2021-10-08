#include "rdnetwork.h"
#include "rderrors.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
        return err_input(argv[0]);
    
    addnetwork();  // TODO: maybe constant version, otherwise i've bo idea how to build tests
    
    rdtype_e type = gettype(argv[1]);
    if(type == ERROR)
        return err_input(argv[0]);
    
    printf("%d\n", getrdquality(type, atoi(argv[2])));
    return 0;
}