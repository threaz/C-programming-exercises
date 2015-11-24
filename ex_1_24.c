#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int ch, prev_ch;
  int state, quote;

  prev_ch = ' '; 
  state = 0;
  quote = 0;

  while((ch = getchar()) != EOF)
    {
      if(state) /* state == IN */
	{
	  if(prev_ch == '*' && ch == '/')
	    {
	      state = OUT;
	      ch = ' ';  /* don't put / on screen */
	    }
	}
      else      /* state == OUT */
	{ 
	  if(ch == '"' && !quote) quote = IN;
	  else if(quote == IN && ch == '"') quote = OUT;

	  if(prev_ch == '/' && ch != '*')
	    {
	      putchar(prev_ch);
	      putchar(ch);
	    }
	  else if(prev_ch == '/' && ch == '*' && quote)
	    {
	      putchar(prev_ch);
	      putchar(ch);
	    }
	  else if(prev_ch == '/' && ch == '*' && !quote)
	    state = IN;
	  else if(ch != '/')
	    putchar(ch);
	}
      prev_ch = ch;
    }
  return 0;
}
