#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main()
{
  char buff[] = "Damian";
  
  reverse(buff);
  
  puts(buff);
  return 0;
}

void reverser(char s[], int left, int right){
  if(left >= right) 
    return;

  char temp = s[left];
  s[left] = s[right];
  s[right] = temp;
  
  reverser(s, ++left, --right);
}

void reverse(char s[])
{
  reverser(s, 0, strlen(s) - 1);
}
