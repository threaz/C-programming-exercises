#include <stdio.h>

/* brackets */
int Round, Square, Curly;

/* apostrophes */
int Sing, Doub;

void is_bracket(int sign);
void is_apostrophe(int sign);

void missing_bracket();

int main()
{
  int ch;

  while((ch = getchar()) != EOF)
    {
      is_bracket(ch);
    }
  
  missing_bracket();
  return 0;
}

void is_bracket(int sign)
{
  if(sign == '(') ++Round;
  else if(sign == '[') ++Square;
  else if(sign == '{') ++Curly;

  if(sign == ')') --Round;
  else if(sign == ']') --Square;
  else if(sign == '}') --Curly;
}

void missing_bracket()
{
  if(Round > 0) 
    printf("%d missing closing round bracket(s).\n", Round);
  
  if(Square > 0) 
    printf("%d missing closing square bracket(s).\n", Square);

  if(Curly > 0) 
    printf("%d missing closing curly bracket(s).\n", Curly);
}
