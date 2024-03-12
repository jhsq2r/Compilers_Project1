#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"

void filter(FILE *dirtyfile, FILE *cleanfile);
void scanner(FILE *file);

#endif
