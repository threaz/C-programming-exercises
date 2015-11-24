#include "numcmp.h"

int numcmp(char *s1, char *s2)
{
  double l1, l2;
  char buf[MAX_STR];
  
  substr(s1, buf);
  l1 = atof(buf);
  substr(s2, buf);
  l2 = atof(buf);

  if(l1 > l2)
    return 1;
  else if(l1 < l2)
    return -1;
  else
    return 0;
}



