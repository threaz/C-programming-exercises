#include <stdio.h>

void _strcat(char *to, char *from);

int main()
{
  char buf[100] = "Damian ";
  char buf1[] = "to super koles";

  _strcat(buf, buf1);
  puts(buf);
  return 0;
}

void _strcat(char *to, char *from)
{
  while(*++to)
    ; 

  for( ;*to = *from; ++to, ++from)
    ;
}
