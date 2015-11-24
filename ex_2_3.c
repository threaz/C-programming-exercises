#include <stdio.h>
#define MAXLINE 1000
#define true 1
#define false 0

int hex_to_dec(const char sign)
{
    if(sign >= '0' && sign <= '9')
        return sign - '0';
    else if(sign >= 'A' && sign <= 'F')
        return sign - 'A' + 10;
    else if(sign >= 'a' && sign <= 'f')
        return sign - 'a' + 10;
    else return -1;
}

int is_hex(const char sign)
{
    if(sign >= '0' && sign <= '9')
        return true;
    else if(sign >= 'A' && sign <= 'F')
        return true;
    else if(sign >= 'a' && sign <= 'f')
        return true;
    else return false;
}


long htoi(char s[])
{
    int pos = 0;
    long n;

    n = 0;
    if(s[pos] == '0' && (s[++pos] == 'x' || s[pos] == 'X'))
    {
        ++pos;
        for( ; is_hex(s[pos]); ++pos)
            n = 16 * n + hex_to_dec(s[pos]);
    }
    return n;
}

int main()
{
    char buffer[MAXLINE];

    while(1)
    {
        scanf("%s", buffer);
        fflush(stdin);

        printf("%d\n", htoi(buffer));
    }
    return 0;
}
