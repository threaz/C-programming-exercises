#include <stdio.h>

#define MAXLINE 1000
#define N_TAB 8

int left_to_tab(int pos, int tab);

int main()
{

	int ch, pos;

	pos = 1;

	while((ch = getchar()) != EOF)
       {
           if(ch == '\t')
           {
               int n_ws = left_to_tab(pos, N_TAB);
               while(n_ws--)
               {
                    putchar('_');
                    ++pos;
               }
           }
           else
           {
                putchar(ch);
                ++pos;
           }

           if(ch == '\n') pos = 1;
       }
    return 0;
}

int left_to_tab(int pos, int tab)
{
    if(pos < 0) return 0;
    return (tab - ((pos - 1) % N_TAB) % N_TAB);
}
