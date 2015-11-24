#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main(int argc, char ** argv)
{
  char bf1[1000] = "a-x -m m-", bf2[2000];

  expand(bf1, bf2);
  printf("%s\n", bf2);
  return 0;
}

void expand(char s1[], char s2[]) /* s2 must have apropriate length */
{
  int i, j, k;
  char prev = ' ', ch;
  char beg, end;
  for(i = 0, k = 0; s1[i] != '\0'; ++i)
    {
      if(s1[i] == '-' && !isspace(prev) && prev != '-')
	{
	  beg = prev;
	  end = s1[++i];
	  
	  --k;
	  if(isspace(end) || end == '\0') 
	    {
	      s2[k++] = prev;
	      s2[k++] = '-';
	      if(end != '\0')
		s2[k++] = end;	      
	    }
	  else
	    {
	      for(j = 0, ch = prev; j <= end - beg; ++j, ++k)
		s2[k] = ch++;
	    }
	}
      else 
	{
	  s2[k] = s1[i];
	  ++k;
	}
      
      prev = s1[i];
    }

  s2[k] = '\0';
}
