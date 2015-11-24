#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

/*
  scanf("%d %f", &x, &y);
 */

#define MAXFORMAT 10

void minscanf(char * fmt, ...)
{
  va_list ap;
  int *iadr;
  double *dadr;
  char *sadr, localfmt[MAXFORMAT], *p, *k;

  va_start(ap, fmt);
  for(p = fmt; *p; ++p)
    {
      // printf("\t%d\n", *p); ?????????????? 
      if(*p != '%')
	continue;
      
      for(k = localfmt, *k++ = *p++; isalnum(*p); ++k, ++p)
	*k = *p;
      *k = '\0';
      
      switch(*(localfmt + 1))
	{
	case 'd':
	case 'i':
	  iadr = va_arg(ap, int *);
	  scanf(localfmt, iadr);
	  break;
	case 'f':
	  dadr = va_arg(ap, double *);
	  scanf(localfmt, dadr);
	  break;
	case 's':
	  sadr = va_arg(ap, char *);
	  scanf(localfmt, sadr);
	  break;
	default:
	  printf("minscanf: nierozpoznana opcja");
	  exit(EXIT_FAILURE);
	  break;
      	}
    }
  va_end(ap);
}

#define MAXSIZE 10

int main()
{
  char tab[MAXSIZE];
  int x;
  
  minscanf("%d", &x);
  printf("\t%d\n", x);
  return 0;
}
