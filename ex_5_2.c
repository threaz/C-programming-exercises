#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int getDouble(double *pd);

int main()
{ 
  double temp_db;
  
  getDouble(&temp_db);
  printf("%f\n", temp_db);
  return 0;
}

int getDouble(double *pd)
{
  int c, sign, i;
  int pow;
  
  while(isspace(c = getchar()))
    continue;
  
  if(!isdigit(c) && c != EOF && c != '.' && c != '-' && c != '+') 
    {
      ungetc(c, stdin);
      return 0;      
    }
  
  if(c == '-' || c == '+')
    {
      sign = (c == '-') ? -1 : 1;
      
      c = getchar();
      if(isdigit(c))
	;
      else 
	{
	  if(c != EOF)
	    ungetc(c, stdin);
	  return 0;
	}
    }
   
  for(pow = 0, *pd = 0.0; isdigit(c) && c != EOF; c = getchar(), ++pow)
    *pd = 10.0 * *pd + (c - '0');
  
  if(c == '.')
    c = getchar();
  
  for( ; isdigit(c) && c != EOF; c = getchar())
    *pd = 10.0 * *pd + (c - '0');

  while(pow--)
    *pd = (*pd) / 10;
  if(sign < 0)
    *pd *= sign;
  
  if(c != EOF)
    ungetc(c, stdin);
  
  return c;
}
