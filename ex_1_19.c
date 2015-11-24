#include "GETLINE.h"
#define MAXSIZE 1000

int max;
void reverse(char s[]);
void bufferCopy(char from[], char to[]);

int main()
{
  int n;

  printf("%d\n", max);
  char buffer[MAXSIZE];

  while((n = GETLINE(buffer, MAXSIZE)) > 0)
    {
      reverse(buffer);
      printf("%s", buffer);
    }
  return 0;
}

void bufferCopy(char from[], char to[])
{
  int i = 0; 
  while((to[i] = from[i]) != '\0') ++i;
}

void reverse(char s[])
{
  int j, k;
  char temp;
  
  j = 0;
  while(s[j] != '\0') ++j;
  
  --j;                  // zostaw '\0'
  if(s[j] == '\n') --j; // zostaw '\n'
  
  k = 0;
  while(k < j)
    {
      temp = s[k];
      s[k] = s[j];
      s[j] = temp;
      ++k;
      --j;
    }
}

