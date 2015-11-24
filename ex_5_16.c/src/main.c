#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lines.h"
#include "quicksort.h"
#include "numcmp.h"
#include "charcmp.h"

#define MAXLINES 500
#define MAXOPT 2

char *lineptr[MAXLINES];

bool numeric = false;
bool reverse = false;
bool fold = false;
bool dict = false;

int main(int argc, char ** argv)
{
  int nlines, i, tmp;
  int optTable[MAXOPT];

  void * cmp_ptr;
  
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
    else if(optTable[i] == 'f')
      fold = true;
    else if(optTable[i] == 'd')
      dict = true;

  if((numeric && fold) || (numeric && dict)) {
    puts("string_sort_cmp: niedozwolona kombinacja opcji");
    return -1;
  }
  else if(numeric) 
    cmp_ptr = numcmp;
  else if(fold || dict)
    cmp_ptr = charcmp;
  else 
    cmp_ptr = strcmp;
 
  
  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      quicksort((void **)lineptr, 0, nlines - 1, 
		(int (*)(void *, void*))(cmp_ptr));
      writelines(lineptr, nlines, reverse);
      return 0;
    }
  else 
    {
      puts("sort_string_num: za duzo wierszy do sortowania");
      return 1;
    }
}
