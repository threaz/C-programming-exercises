#include <stdio.h>
#include "calc.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else 
    printf("blad: pelen stos, nie mozna umiescic %f\n", f);
}

double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else 
    {
      printf("blad: pusty stos\n");
      return 0.0;
    }
}

void clear(void)
{
  s = 0;
  printf("clear: stos wyczyszczony\n");
}
