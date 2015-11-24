#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

#define MAXFORMAT 20
void miniprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  char localfmt[MAXFORMAT], *k;
  int ival;
  double dval;

  va_start(ap, fmt);
  for(p = fmt; *p; ++p)
    {
      if(*p != '%')
	{
	  putchar(*p);
	  continue;
	}
      
      for(k = localfmt, *k++ = *p; isalnum(*p); ++p, ++k)
	*k = *p;

      switch(*(localfmt + 1))
	{
	case 'd':
	case 'i':
	  ival = va_arg(ap, int);
	  printf(localfmt, ival);
	  break;
	case 'f':
	  dval = va_arg(ap, double);
	  printf(localfmt, dval);
	  break;
	case 's':
	  sval = va_arg(ap, char *);
	  printf(localfmt, sval);
	  break;
	default:
	  putchar(*p);
	  break;
	}
    }
  va_end(ap);
}

int main()
{
  printf("%10s\n", "mama");
  return 0;
}
