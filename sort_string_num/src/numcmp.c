#include "numcmp.h"

int numcmp(char *s1, char *s2)
{
  double l1, l2;

  l1 = atof(s1);
  l2 = atof(s2);

  if(l1 > l2)
    return 1;
  else if(l1 < l2)
    return -1;
  else
    return 0;
}
