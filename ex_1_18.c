#include <stdio.h>
#define MAXSIZE 1000

int GETLINE(char chTab[], int nTab);
void bufferFlush(char chTab[]);
void bufferCopy(char from[], char to[]);
int remove_space(char chTab[], int nTab);

int main()
{
  int n;
  char buffer[MAXSIZE];

  while((n = GETLINE(buffer, MAXSIZE)) > 0)
    {
      if(remove_space(buffer, n))
	bufferFlush(buffer);
    }
  return 0;
}

int remove_space(char chTab[], int nTab)
{
  int i;
  for(i = nTab - 3; i >= 0 && (chTab[i] == ' ' || chTab[i] == '\t') ; --i)
    continue;    /* - 2 bo pomijamy newline  i '\0' */

  if(i < 0) return 0; // wiersz jest pusty
  else if(i > nTab - 2)
    {
      chTab[i++] = '\n';
      chTab[i] = '\0';
      return i;
    }
}

void bufferCopy(char from[], char to[])
{
  int i = 0; 
  while((to[i] = from[i]) != '\0') ++i;
}

void bufferFlush(char chTab[])
{
  printf("%s", chTab);
}

int GETLINE(char chTab[], int nTab)
{
  int i, ch;

  for(i = 0; (ch = getchar()) != EOF && ch != '\n' && i != nTab - 1; ++i)
    chTab[i] = ch;

  if(ch == '\n')
    {
      chTab[i] = '\n';
      ++i;
    }
  chTab[i] = '\0';
  
  return i;
}
