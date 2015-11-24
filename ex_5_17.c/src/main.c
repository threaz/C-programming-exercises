#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lines.h"
#include "quicksort.h"
#include "numcmp.h"
#include "charcmp.h"
#include "get_options.h"
#include "substr.h"

#define MAXLINES 500
#define MAXOPT 2

char *lineptr[MAXLINES];

bool numeric = false;
bool reverse = false;
bool fold = false;
bool dict = false;
int from = -1;
int to = -1;

int main(int argc, char ** argv)
{
  int nlines;
  void * cmp_ptr;
  
  if(get_options(argc, argv) < 0)
    return -1;
  printf("\tfrom: %d to: %d\n", from, to);

   if((numeric && fold) || (numeric && dict)) {
    puts("string_sort_num: niedozwolona kombinacja opcji");
    return -1;
  }
  else if(numeric) 
    cmp_ptr = numcmp;
  else 
    cmp_ptr = charcmp;
  
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
