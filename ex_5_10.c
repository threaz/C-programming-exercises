#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include </home/threaz/Pulpit/c/stack.h>

#define BUFF_SIZE 100
#define IS_OPERATION(x) ((x == '+') || (x == '-') || (x == '/') || (x == '*'))

int main(int argc, char *argv[])
{
  char buf[BUFF_SIZE];
  int ch;
  int flag_zero_div = 0;

  if(argc < 2)
    {
      printf("format wywolania: program arg1 [arg2, arg3...]\n");
      return 1;
    }

  while(--argc > 0)
    {
      ch = (*++argv)[0];
      if(isdigit(ch))
	{
	  int i = 0;
	  buf[i++] = ch;

	  while(isdigit(ch = *++(*argv)))
	    buf[i++] = ch;
	    
	  if(ch == '.')
	    {
	      buf[i++] = ch;
	      while(isdigit(ch = *++(*argv)))
		buf[i++] = ch;
	    }

	  if(ch == '\0')
	    buf[i] = '\0';

	  push(atof(buf));
	}
      else if(IS_OPERATION(ch))
	{
	  double op;

	  switch(ch){
	  case '+':
	    push(pop() + pop());
	    break;
	  case '-':
	    op = pop();
	    push(pop() - op);
	    break;
	  case '*':
	    push(pop() * pop());
	    break;
	  case '/':
	    op = pop();
	    if(op == 0.0)
		printf("blad: dzielenie przez 0.0\n");
	      
	    else
	      push(pop() / op);
	    break;

	    }
	}
    }

  printf("\t%.3g\n", pop());
  
  return 0;
}
