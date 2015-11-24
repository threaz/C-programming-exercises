#include <stdio.h>
#include <ctype.h>

#define SIZE 5

int getint(int * pn);

int main(){
  while(1)
    {
      int t, m;

      m = getint(&t);
      printf("getint: %d, t: %d\n", m, t);
    }
}


int getint(int * pn){
  
  int c, sign;
  
  while(isspace(c = getchar()))
    continue;
  
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetc(c, stdin);
    return 0;
  }

  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-'){
    c = getchar();
    if(isspace(c)){
      if(c != EOF)
	ungetc(c, stdin);
      return 0;
    }
  }
  for(*pn = 0; isdigit(c); c = getchar())
    *pn = *pn * 10 + (c - '0');

  *pn *= sign;
  if(c != EOF)
    ungetc(c, stdin);
  
  return c;
}
