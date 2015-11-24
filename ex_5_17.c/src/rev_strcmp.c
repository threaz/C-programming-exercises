#include "rev_strcmp.h"

int rev_strcmp(char * s1, char * s2)
{
  int t_c1, t_c2;
  
  while((t_c1 = tolower(*(s1++))) == (t_c2 = tolower(*(s2++))))
    if(t_c1 == '\0')
      return 0;

  return t_c1 - t_c2;
}
