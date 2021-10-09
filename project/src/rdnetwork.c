#include "rdnetwork.h"

#include <stdio.h>
#include <string.h>

rdlist_t *rdroot;

rdtype_e gettype(char *type)
{
    if (!strcmp(type, "priming"))
        return PRIMING;
    if (!strcmp(type, "grass"))
        return GRASS;
    if (!strcmp(type, "asphalt"))
        return ASPHALT;
    if (!strcmp(type, "concrete"))
        return CONCRETE;
    return ERROR;
}

// hardcode cause the task is not clear enough for me
void addnetwork()
{
    appendroad((rdnetwork_t){3001,  PRIMING,    BAD,        1});
    appendroad((rdnetwork_t){2000,  PRIMING,    TERRIBLE,   1});
    appendroad((rdnetwork_t){4000,  PRIMING,    BAD,        1});
    appendroad((rdnetwork_t){3000,  PRIMING,    TERRIBLE,   1});
    appendroad((rdnetwork_t){2000,  PRIMING,    NORM,       2});

    appendroad((rdnetwork_t){1500,  GRASS,      TERRIBLE,   1});
    appendroad((rdnetwork_t){3600,  GRASS,      BAD,        1});
    appendroad((rdnetwork_t){7080,  GRASS,      TERRIBLE,   1});
    appendroad((rdnetwork_t){1000,  GRASS,      TERRIBLE,   1});
    appendroad((rdnetwork_t){500,   GRASS,      BAD,        2});

    appendroad((rdnetwork_t){5100,  ASPHALT,    NORM,       2});
    appendroad((rdnetwork_t){2800,  ASPHALT,    GOOD,       2});
    appendroad((rdnetwork_t){2700,  ASPHALT,    NORM,       2});
    appendroad((rdnetwork_t){2800,  ASPHALT,    GREAT,      2});
    appendroad((rdnetwork_t){3200,  ASPHALT,    NORM,       3});

    appendroad((rdnetwork_t){3300,  CONCRETE,   BAD,        2});
    appendroad((rdnetwork_t){6900,  CONCRETE,   GOOD,       2});
    appendroad((rdnetwork_t){3400,  CONCRETE,   GOOD,       2});
    appendroad((rdnetwork_t){4400,  CONCRETE,   GREAT,      2});
    appendroad((rdnetwork_t){5601,  CONCRETE,   GREAT,      3});
}

rdquality_e getrdquality(rdtype_e type, unsigned int numlanes)
{
    rdlist_t *rdnode = rdroot;
    int sumqual = 0;
    int numroads = 0;
    while (rdnode != NULL)
    {
        if(rdnode->data.type == type && rdnode->data.numlanes == numlanes)
        {
            ++numroads;
            sumqual += rdnode->data.quality;
        }
        rdnode = rdnode->next;
    }
    if(numroads == 0)
        return ERROR;
    
    float avgqual = (float)sumqual / numroads;
    if(avgqual < (TERRIBLE + BAD) / 2.f)
        return TERRIBLE;
    if(avgqual < (NORM + BAD) / 2.f)
        return BAD;
    if(avgqual < (NORM + GOOD) / 2.f)
        return NORM;
    if(avgqual < (GOOD + GREAT) / 2.f)
        return GOOD;
    return GREAT;
}
