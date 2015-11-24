#include <stdio.h>

int itoa(int num, char s[]);

int main()
{
  char buff[100];			      
  itoa(-1234, buff);

  printf("%s\n", buff);
  return 0;
}

int itoa(int num, char s[])
{
  static int i = 0, k = 0;
  
  if(num < 0) 
    {
      s[i++] = '-';
      num = -num;
    }
  
  if(num > 0)
    {
      ++k;
      itoa(num / 10, s);
    }
  
  if(num == 0)
    s[--k] = '\0';
  else 
    {
      s[i++] = num % 10 + '0';
    }

  return 0;
}
