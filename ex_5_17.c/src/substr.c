#include "substr.h"

void substr(char * string, char * sub)
{
  int beg, end;
  int i, j;

  beg = (from == -1) ? 0 : from;  
  end = (to == -1) ? strlen(string) : to;

  for(i = beg, j = 0; i <= end; ++i, ++j)
    sub[j] = string[i];
  
  sub[j] = '\0';
}
