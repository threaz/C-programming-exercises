#include <stdio.h>

#define N_TAB 8

int left_to_tab(int pos, int tab);

int main()
{
    int n_w, n_t, ch;
    int pos;

    pos = 1;
    n_w = n_t = 0;
    while((ch = getchar()) != EOF)
    {
        if(ch == ' ')
        {
            if(pos % N_TAB != 0)
                ++n_w;
            else
            {
                n_w = 0;
                ++n_t;
            }
            ++pos;
        }
        else
        {
            for( ; n_t > 0; --n_t)
                putchar('\t');
            if(ch == '\t')
                n_w = 0;
            else
                for( ; n_w > 0; --n_w)
                    putchar(' ');
            putchar(ch);

            if(ch == '\n')
                pos = 1;
            else if(ch == '\t')
                pos += left_to_tab(pos, N_TAB) - 1;
            else
                ++pos;
        }
    }
    return 0;
}

int left_to_tab(int pos, int tab)
{
    return N_TAB - (pos - 1) % N_TAB;
}

