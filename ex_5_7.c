#include <stdio.h>
#include <string.h>
#include "/home/threaz/Pulpit/c/Getline.h"
#include "/home/threaz/Pulpit/c/K&R/alloc/alloc.c"

#define MAXLINES 5000
#define MAXBUF 10000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *linestore, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

int main()
{
  int nlines;
  char buf[MAXBUF];

  if((nlines = readlines(lineptr, buf, MAXLINES)) >= 0)
    {
      qsort(lineptr, 0, nlines - 1);
      writelines(lineptr, nlines);
      return 0;
    }
  else
    {
      puts("blad: za duzo wierszy do sortowania");
      return 1;
    }
}

#define MAXLEN 1000

char *alloc(int);

int readlines(char *lineptr[], char *linestore, int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  char *end;
  
  nlines = 0;
  p = linestore;
  end = p + MAXBUF - 1;
  
  while((len = Getline(line, MAXLEN)) > 0)
    if(nlines >= maxlines || p + len > end)
      return -1;
    else 
      {
	line[len - 1] = '\0';
	strcpy(p, line);
	lineptr[nlines++] = p;
	p += len;
      }

  return nlines;
}

void writelines(char *lineptr[], int nlines)
{
  int i;
  
  for(i = 0; i < nlines; ++i)
    puts(lineptr[i]);
}


void swap(char *v[], int i, int j)
{
  char * tmp_ptr;

  tmp_ptr = v[i];
  v[i] = v[j];
  v[j] = tmp_ptr;
}


void qsort(char *v[], int left, int right)
{
  int i, last;

  if(left >= right)
    return;

  swap(v, left, (left + right) / 2);
  last = left;

  for(i = left + 1; i <= right; ++i)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  
  swap(v, left, last);
  qsort(v, left, last - 1);
  qsort(v, last + 1, right);
}
