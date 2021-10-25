#ifndef RDLIST_H
#define RDLIST_H

typedef enum {
    TERRIBLE = 1,
    BAD,
    NORM,
    GOOD,
    GREAT,
} rdquality_e;

typedef enum {
    ERROR = -1,
    PRIMING = 1, // грунт
    GRASS,
    ASPHALT,
    CONCRETE,
} rdtype_e;

typedef struct {
    unsigned int length;
    rdtype_e type;
    rdquality_e quality;
    unsigned int numlanes;
} rdnetwork_t;

typedef struct rdlist_s {
    rdnetwork_t data;
    struct rdlist_s* next;
} rdlist_t;

extern rdlist_t* rdroot;

void appendroad(rdnetwork_t node);
void freenetwork();

#endif
