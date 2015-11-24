#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lines.h"
#include "quicksort.h"
#include "numcmp.h"

#define MAXLINES 500
#define MAXOPT 2
char *lineptr[MAXLINES];

int main(int argc, char ** argv)
{
  int nlines, i, tmp;
  int optTable[MAXOPT];
  bool numeric = false;
  bool reverse = false;

  /*
    int converse = 1;
    -1 -> rev_strcmp;
    0  -> numcmp;
    1  -> strcmp;
   */
  
  i = 0;
  while(--argc > 0 && (*++argv)[0] == '-')
    {
      while((tmp = *++argv[0]) != '\0')
	optTable[i++] = tmp;
    }
  
  while(i--)
    if(optTable[i] == 'n')
      numeric = true;
    else if(optTable[i] == 'r')
      reverse = true;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      quicksort((void **)lineptr, 0, nlines - 1, 
		(int (*)(void *, void*))((numeric) ? numcmp : strcmp));
      writelines(lineptr, nlines, reverse);
      return 0;
    }
  else 
    {
      puts("sort_string_num: za duzo wierszy do sortowania");
      return 1;
    }
}
