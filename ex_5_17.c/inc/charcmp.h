#ifndef CHARCMP_H
#define CHARCMP_H

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "substr.h"

#define MAX_STR 1000

extern bool fold;
extern bool dict;

int charcmp(char * s1, char * s2);

#endif
