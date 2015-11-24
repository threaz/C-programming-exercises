#include <stdio.h>

#define MAX_LINE 15
#define N_TAB 8

char buffer[MAX_LINE];

int find_last_space(int pos)
{
    --pos;
    while(pos-- >= 0)
        if(buffer[pos] == ' ')
            return pos;
    return MAX_LINE;
}

void print_to_pos(int pos)
{
    int i;
    for(i = 0; i < pos; ++i)
        putchar(buffer[i]);
    putchar('\n');
}

int rebuild_buffer(int pos)
{
    int i;
    /* pos == space position, so increase pos */
    ++pos;
    for(i = 0; pos < MAX_LINE; ++i, ++pos)
        buffer[i] = buffer[pos];

    return i;
}

int insert_tab(int pos)
{
    int n = (N_TAB - pos % N_TAB);
    int i;

    for(i = 0; i < n; ++i)
        buffer[pos + i] = ' ';

    return pos += n;
}

int main()
{
    int ch, pos;

    pos = 0;

    while((ch = getchar()) != EOF)
    {
        if(ch == '\t')
            pos = insert_tab(pos);
        else
            if(pos >= 0 && pos < MAX_LINE)
                {
                    buffer[pos] = ch;
                    ++pos;
                }
            else if(pos == MAX_LINE)
            {
                int space_pos;

                space_pos = find_last_space(pos);
                print_to_pos(space_pos);
                pos = rebuild_buffer(space_pos);

                buffer[pos] = ch;
                ++pos;
            }


    }
    return 0;
}

