#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct key {
  char * word;
  int count;
} keytab[] = {
  "auto", 0,
  "break", 0,
  "case", 0,
  "char", 0,
  "const", 0,
  "continue", 0,
  "default", 0,
  "unsigned", 0,
  "void", 0,
  "volatile", 0,
  "while", 0
};

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct key))

int getword(char * word, int max);
int binsearch(char * word, struct key tab[], int n);

int main()
{
  int n;
  char word[MAXWORD];

  while(getword(word, MAXWORD) != EOF)
    {
      if(isalpha(word[0]))
	if((n = binsearch(word, keytab, NKEYS)) > 0)
	  keytab[n].count++;
    }

  for(n = 0; n < NKEYS; ++n)
    if(keytab[n].count > 0)
      printf("\t%4d %s\n", keytab[n].count, keytab[n].word);
  
  return 0;
}

int binsearch(char * word, struct key tab[], int n)
{
  int l, r, m;
  int cond;

  l = 0;
  r = n - 1;
  
  while(l <= r)
    {
      m = (l + r) / 2;
      
      if((cond = strcmp(word, tab[m].word)) < 0)
	r = m - 1;
      else if(cond > 0)
	l = m + 1;
      else 
	return m;
    }
  return -1;
}

int getword(char * word, int max)
{
  int c, prev;
  char * w = word;

  while(isspace(c = getchar()))
    ;

  if(c != EOF)
    *w++ = c;

  if(!isalpha(c) && c != '/' && c != '_' && c != '\"' && c != '#') {
    *w = '\0';
    return c;
  }
  
  if(c == '/' && (*w = getchar()) == '*') /* discard comments */
    {
      prev = ' ';
      while(prev != '*' || c != '/')
	{
	  prev = c;
	  c = getchar();
	}	

      return '/';
    }
  else if(c == '\"') /* discard strings */
    {
      c == ' ';
      while((c = getchar()) != '\"')
	;
      
      return '\"';
    }
  else if(c == '#')
    {
      while((c = getchar()) != '\n')
	;
      return '#';
    }
  
  for( ; --max > 0; w++) {
    if(!isalnum(*w = getchar())) {
      ungetc(*w, stdin);
      break;
    }
  }
  
  *w = '\0';
  return word[0];
}
