#include <stdio.h>
#include <string.h>
#include "/home/threaz/Pulpit/c/Getline.h"

#define MAXLINE 1000

int main(int argc, char ** argv)
{
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;
  
  while(--argc > 0 && (*++argv)[0] == '-')
    {
      while(c = *++argv[0]) /* each arg is ended with \0 */
	switch(c)
	  {
	  case 'x':
	    except = 1;
	    break;
	  case 'n':
	    number  = 1;
	    break;
	  default:
	    printf("find: nieznana opcja %c\n", c);
	    argc = 0;
	    found = -1;
	    break;
	  }
    }
  if(argc != 1)
    printf("Format wywolania: find -x -n wzorzec\n");
  else
    {
      while(Getline(line, MAXLINE) > 0)
	{
	  lineno++;
	  if((strstr(line, *argv) != NULL) != except)
	    {
	      if(number)
		printf("%ld:", lineno);
	      printf("%s", line);
	      ++found;
	    }
	}
    }

  return found;
}
