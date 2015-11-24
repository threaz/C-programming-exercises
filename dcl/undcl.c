#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);

int gettoken(void);
int next_token(void);

int tokentype;
int prev_token;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int main()
{ 
  int type;
  char temp[MAXTOKEN];
  
  while(gettoken() != EOF)
    {
      prev_token = NO;
      strcpy(out, token);
      while((type = gettoken()) != '\n')
	{
	  if(type == PARENS || type == BRACKETS)
	    strcat(out, token);
	  else if(type == '*')
	    {
	      if((type = next_token()) == PARENS 
		 || type == BRACKETS)
		sprintf(temp, "(*%s)", out);
	      else 
		sprintf(temp, "*%s", out);
	      strcpy(out, temp);
	    }
	  else if(type == NAME)
	    {
	      sprintf(temp, "%s %s", token, out);
	      strcpy(out, temp);
	    }
	  else
	    printf("niepoprawne dane wejsciowe: %s\n", token); 
	}
      printf("%s\n", out);
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
  extern int prev_token;
  
  if(prev_token == YES){
    prev_token = NO;
    return tokentype;
  }
  
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

int next_token(void)
{
  extern int prev_token;
  int type;

  type = gettoken();
  prev_token = YES;
  return type;
}
