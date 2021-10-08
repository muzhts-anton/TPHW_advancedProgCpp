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