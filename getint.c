#include <stdio.h>
#include <ctype.h>

#define SIZE 5

int getint(int * pn);

int main(){
  
  int n, arr[SIZE];
  
  for(n = 0; n < SIZE && getint(&arr[n]) != EOF; ++n)
    continue;
  
  for(n = 0; n < SIZE; ++n)
    printf("%d ", arr[n]);
  
  puts(" ");
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
  if(c == '+' || c == '-')
    c = getchar();
  
  for(*pn = 0; isdigit(c); c = getchar())
    *pn = *pn * 10 + (c - '0');

  *pn *= sign;
  if(c != EOF)
    ungetc(c, stdin);
  
  return c;
}
