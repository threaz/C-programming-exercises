#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "lines.h"
#include "quicksort.h"
#include "numcmp.h"

#define MAXLINES 500
char *lineptr[MAXLINES];

int main(int argc, char ** argv)
{
  int nlines;
  bool numeric = false;

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = true;

  if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
      quicksort((void **)lineptr, 0, nlines - 1, 
		(int (*)(void *, void*))((numeric) ? numcmp : strcmp));
      writelines(lineptr, nlines);
      return 0;
    }
  else 
    {
      puts("sort_string_num: za duzo wierszy do sortowania");
      return 1;
    }
}
