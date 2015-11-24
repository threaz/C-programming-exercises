#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int tokentype;
int error_occured;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main()
{ 
  while(gettoken() != EOF)
    {
      error_occured = 0;

      strcpy(datatype, token);
      out[0] = '\0';
      dcl();

      if(tokentype != '\n') {
	printf("blad skladniowy\n");
	error_occured = 1;
      }
      
      if(!error_occured){
	printf("%s: %s %s\n", name, out, datatype);
	error_occured = 0;
      }
    }

  return 0;
}

void dcl(void)
{
  int ns;
  
  for(ns = 0; gettoken() == '*'; )
    ns++;
  
  dirdcl();
  while(ns-- > 0)
    strcat(out, " wskaznik do");
}

void dirdcl(void)
{
  int type;
  
  if(tokentype == '(')
    {
      dcl();
      if(tokentype != ')')
	printf("blad: brak nawiasu )\n");
    }
  else if(tokentype == NAME)
    strcpy(name, token);
  else 
    printf("blad: spodziewana nazwa lub (deklarator)\n");
  while((type = gettoken()) == PARENS || type == BRACKETS)
    if(type == PARENS)
      strcat(out, " funkcja zwracajaca");
    else
      {
	strcat(out, " tablica");
	strcat(out, token);
	strcat(out, " o elementach");
      }
}

int gettoken(void)
{
  int c;
  char *p = token;

  while((c = getchar()) == ' ' || c == '\t')
    ;
  if(c == '(')
    {
      if((c = getchar()) == ')')
	{
	  strcpy(token, "()");
	  return tokentype = PARENS;
	}
      else
	{
	  ungetc(c, stdin);
	  return tokentype = '(';
	}
    } 
  else if(c == '[')
    {
      for(*p++ = c; (*p++ = getchar()) != ']'; )
	;
      *p = '\0';
      return tokentype = BRACKETS;
    }
  else if(isalpha(c))
    {
      for(*p++ = c; isalnum(c = getchar()); )
	*p++ = c;
      *p = '\0';
      ungetc(c, stdin);
      return tokentype = NAME;
    }
  else 
    return tokentype = c;
}
