#include "stat.h"

int main()
{
    int *tmp = mystat();
    free(tmp);
    return 0;
}
