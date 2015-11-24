#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include "calc.h"

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i,c;
  
  while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  i = 0;

  if(c == '\n')
    return c;
  
  if(!isdigit(c) && c != '.' && c != '-')
    if(!isalpha(s[++i] = c = getch()))
      {
	ungetch(c);
	return s[0];
      }
    else if(isalpha(c))
      {
	while(isalpha(s[++i] = c = getch()))
	  ;
	printf("%d\n", i);
	s[i] = '\0';
	ungetch(c);
	return WORD;
      }

  if(c == '-')
    if(isdigit(c = getch()) || c == '.')
      s[++i] = c;
    else
      {
	if(c != EOF)
	  ungetch(c);
	return '-';
      }

  if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')
    while(isdigit(s[++i] = c = getch()))
      ;  
  
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);

  return NUMBER;
}

#define BUFFSIZE 100
int buf = ' ';
int bufp = 0;

int getch(void)
{
  if(bufp == 0)
    return getchar();
  else 
    {
      bufp = 0;
      return buf;
    }
}
void ungetch(int c)
{
  if(buf >= 1)
    printf("ungetch: za duzo zwrotow\n");
  else 
    {
      bufp = 1;
      buf = c;
    }
}

void ungetch_string(char s[])
{
  int len  = strlen(s);
  
  while(len > 0)
    ungetch(s[--len]);
}
