#ifndef RDNETWORK_H
#define RDNETWORK_H

#include "rdlist.h"

rdtype_e gettype(char* type);
void addnetwork();
rdquality_e getrdquality(rdtype_e type, unsigned int numlanes);

#endif