#include "Getline.h"

int Getline(char chTab[], int nTab)
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
