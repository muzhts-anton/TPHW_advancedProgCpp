#include "rdlist.h"

#include <stdlib.h>

rdlist_t *rdroot;

void appendroad(rdnetwork_t node)
{
    rdlist_t *tmp = rdroot;
    if(!rdroot) {
        rdroot = (rdlist_t *)malloc(sizeof(rdlist_t));
        if(!rdroot)
            exit(-1);
        tmp = rdroot;
    } else {
        while(tmp->next)
            tmp = tmp->next;

        tmp->next = (rdlist_t *)malloc(sizeof(rdlist_t));
        if(!tmp->next)
            exit(-1);
        tmp = tmp->next;
    }

    tmp->data.length = node.length;
    tmp->data.type = node.type;
    tmp->data.quality = node.quality;
    tmp->data.numlanes = node.numlanes;
    tmp->next = NULL;
}

void freenetwork()
{
    rdlist_t *delr1 = rdroot;
    rdlist_t *delr2 = rdroot;
    if(rdroot)
        delr2 = delr2->next;
    while(delr1)
    {
        free(delr1);
        delr1 = delr2;
        if(delr2)
            delr2 = delr2->next;
    }
    rdroot = NULL;
}
