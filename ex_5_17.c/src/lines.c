#include "lines.h"

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = Getline(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else 
      {
	line[len - 1] = '\0';
	strcpy(p, line);
	lineptr[nlines++] = p;
      }

  return nlines;
}

void writelines(char *lineptr[], int nlines, bool rev)
{
  int i;
  
  if(!rev)
    for(i = 0; i < nlines; ++i)
      puts(lineptr[i]);
  else 
    for(i = nlines - 1; i >= 0; --i)
      puts(lineptr[i]);
}
