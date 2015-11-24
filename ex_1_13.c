#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXLEN 15

int main()
{
  int c, word_len = 0, i, k;
  int nword[MAXLEN];
  int state = OUT;
  int ovrflow = 0;
  
  for(i = 0; i < MAXLEN; ++i) nword[i] = 0; // zero-init table

  while((c = getchar()) != EOF)
    {
      if(c == ' ' || c == '\t' || c == '\n')
	{
	  if(state == IN) // end of the word
	    {
	      if(word_len >= MAXLEN)
		++ovrflow;
	      else
		++nword[word_len];
				
	      word_len = 0;
	      state = OUT;
	    }
	}
      else if(state == OUT) // beginnig of the word
	{
	  ++word_len;
	  state = IN;
	}
      else // in word
	++word_len;
    }

  for(i = 1; i < MAXLEN; ++i)
    {
      printf("%2d: ", i);
      if(nword[i] == 0) putchar('\n');
      else
	{
	  // print histogram
	  for(k = 1; k <= nword[i]; ++k)
	    putchar('+');
	  putchar('\n');
	}
    }
  printf("Too long words: ");
  for(i = 1; i <= ovrflow; ++i)
    putchar('+');
  return 0;
}
