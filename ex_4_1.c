#include <stdio.h>
#define MAXLINE 100

char pattern[] = "Damian";


int getline(char s[], int lim)
{
    int ch, i;

    i = 0;
    while(--lim > 0 && (ch = getchar()) != EOF && ch != '\n')
        s[i++] = ch;

    if(ch == '\n')
        s[i++] = ch;

    s[i] = '\0';
    return i;
}

int strrindex(char line[], char patt[])
{
    int i, j ,k, m;

    m = -1;
    for(i = 0; line[i] != '\0'; ++i)
    {
     for(j = i, k = 0; patt[k] != '\0' && line[j] == patt[k]; ++j, ++k)
        ;
        if(patt[k] == '\0' && k > 0)
            m = i;
    }

    return m;
}

int main()
{
    char buffer[MAXLINE];

    int i = 0, x;

    while(getline(buffer, MAXLINE) > 0)
        if((x = strrindex(buffer, pattern)) >= 0)
        {
            printf("%s", buffer);
            printf("pos: %d\n", x);
            ++i;
        }

    return i;
}
