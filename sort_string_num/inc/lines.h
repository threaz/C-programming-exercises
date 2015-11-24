#ifndef LINES_H
#define LINES_H

#define MAXLEN 1000

#include <stdio.h>
#include "alloc.h"
#include "Getline.h"

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
char *strcpy(char *dest, const char *src);


#endif
