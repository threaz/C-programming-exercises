#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include </home/threaz/Pulpit/c/K&R/alloc/alloc.c>
#include </home/threaz/Pulpit/c/Getline.h>

int readlines(char ** lineBuf, int maxLine);

#define MAX_LINES 10000

int main(int argc, char ** argv)
{
  int linesRead = 0, linesToDisp;
  char * lineBuf[MAX_LINES], numBuf[MAX_LINES];
  int tmp, i;

  if(argc == 1)
    linesToDisp = 10;
  else if(argc > 2)
    {
      puts("there's only one parameter allowed to be passed");
      return 10;
    }
  else
    if((*++argv)[0] == '-'){
      tmp = (*++argv[0]);
      if(!isdigit(tmp)){
	puts("blad: nieznana opcja");
	return -1;
      }
      else {
	i = 0;
	numBuf[i++] = tmp;
	while(isdigit(tmp = *++argv[0]))
	  numBuf[i++] = tmp;

	numBuf[i] = '\0';
	linesToDisp = atoi(numBuf);
      }

    }
    else {
      puts("blad: nieznana opcja");
      return -1;
    }
  
  if((linesRead = readlines(lineBuf, MAX_LINES)) > 0)
    {
      if(linesRead <= linesToDisp)
	for(i = 0; i < linesRead; ++i)
	  puts(lineBuf[i]);
      else {
	for(i = linesRead - linesToDisp; i < linesRead; ++i)
	  puts(lineBuf[i]);
      }
    }
  
  return 0;
}

#define MAX_BUF 1000

int readlines(char ** lineBuf, int maxLine)
{
  int len, nlines;
  char * ptr, tempBuf[MAX_BUF];
  
  nlines = 0;

  while((len = Getline(tempBuf, MAX_BUF)) > 0)
      if(nlines >= maxLine || (ptr = alloc(len)) == NULL)
	return -1;
      else {
	tempBuf[len - 1] = '\0';
	strcpy(ptr, tempBuf);
	lineBuf[nlines++] = ptr;
      }

  return nlines;
}
