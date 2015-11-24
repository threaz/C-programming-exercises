#include "charcmp.h"

int charcmp(char * s1, char * s2, bool fold, bool dir)
{
  int c1, c2;

  do {
    if(dir) {
      while(*s1 != ' ' && *s1 != '\0' && !isalnum(*s1))
	++s1;
      while(*s2 != ' ' && *s2 != '\0' && !isalnum(*s2))
	++s2;
    }

    c1 = (fold) ? tolower(*s1) : *s1;
    ++s1;

    c2 = (fold) ? tolower(*s2) : *s2;
    ++s2;

    if(c1 == c2)
      if(c1 == '\0') 
	return 0;
  } while(c1 == c2);

  return c1 - c2;
}
