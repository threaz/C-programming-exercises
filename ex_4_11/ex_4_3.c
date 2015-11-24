#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include  "calc.h"

#define MAXOP 100

void mathfun(char s[]);

int main()
{
  int type, i, var = 0;
  double last = 0.0; /* symbol = l */
  double op2, op3;
  char s[MAXOP];
  double variable[26];
  
  for(i = 0; i < 26; ++i)
    variable[i] = 0.0;
  
  while((type = getop(s)) != EOF)
    {
      switch(type)
	{
	case NUMBER:
	  push(atof(s));
	  break;
	case '+':
	  push(pop() + pop());
	  break;
	case '-':
	  op2 = pop();
	  push(pop() - op2);
	  break;
	case '*':
	  push(pop() * pop());
	  break;
	case '/':
	  op2 = pop();
	  if(op2 == 0.0)
	    printf("blad: dzielenie przez 0.0\n");
	  else
	    push(pop() / op2);
	  break;
	case '%':
	  op2 = pop();
	  if(op2 == 0.0)
	    printf("blad: dzielenie przez 0.0\n");
	  else
	    push((int)pop() % (int)op2);
	  break;
	case '\n':
	  printf("\t%.8g\n", last = pop());
	  break;
	case 'p':
	  op2 = pop();
	  printf("\t%.8g\n", op2);
	  push(op2);
	  break;
	case 'd':
	  op2 = pop();
	  push(op2);
	  push(op2);
	  break;
	case 'c':
	  op2 = pop();
	  op3 = pop();
	  push(op2);
	  push(op3);
	  break;
	case WORD:
	  mathfun(s);
	  break;
	case 'l':
	  push(last);
	  break;
	case '=':
	  pop();
	  if(var >= 'A' && var <= 'Z')
	    variable[var - 'A'] = pop();
	  else 
	    printf("nieznana zmienna %c\n", type);
	  break;
    	default:
	  if(type >= 'A' && type <= 'Z')
	    {
	      push(variable[type - 'A']);
	      var = type;
	    }
	  else
	    printf("nieznane polecenie %s\n", s);
	  break;
	}
    }
  return 0;
}

void mathfun(char s[])
{
  if(!strcmp(s, "sin"))
    push(sin(pop()));
  else if(!strcmp(s, "tan"))
    push(tan(pop()));

  /* add more mathematical functions */
}
