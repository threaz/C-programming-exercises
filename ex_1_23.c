#include <stdio.h>

int main()
{
    int ch, prev_ch = ' ';
    int dq_flag, comment_flag;

    dq_flag = comment_flag = 0;
    while((ch = getchar()) != EOF)
    {x
        if((ch == '*' && prev_ch == '/'))
            comment_flag = 1;
        else
            putchar(ch);
        prev_ch = ch;
    }
    return 0;
}
