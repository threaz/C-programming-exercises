#include <stdio.h>
#define MAXLINE 100

void escape(char to[], char from[])
{
    int i = 0; /* control to[] */
    int j = 0; /* control from[] */

    while(from[j] != '\0')
    {
        switch(from[j])
        {
        case '\t':
            to[i++] = '\\';
            to[i++] = 't';
            ++j;
            break;
        case '\n':
            to[i++] = '\\';
            to[i++] = 'n';
            ++j;
            break;
        default:
            to[i++] = from[j++];
            break;
        }
    }
    to[i] = '\0';
}

int main()
{
    char buff1[MAXLINE] = "damian\tmama    \n", buff2[MAXLINE];

    escape(buff2, buff1);

    printf("%s\n", buff2);
    return 0;
}
