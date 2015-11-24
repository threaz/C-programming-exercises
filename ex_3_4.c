#include <stdio.h>

void reverse(char s[])
{
    int i, j, k;
    int temp;

    for(i = 0; s[i] != '\0'; ++i)
        continue;

    for(j = 0, k = --i; j < k; j++, --k)
        {
            temp = s[j];
            s[j] = s[k];
            s[k] = temp;
        }
}

void itoa(int n, char s[])
{
    int i, sign, tmp;

    if(n < 0) sign = -1;
    else sign = 1;

    for(i = 0; n != 0; ++i)
    {
        tmp = (n % 10);
        s[i] = tmp < 0 ? (-tmp) + 48 : tmp + 48;
        n /= 10;
    }

    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
}

int main()
{
    char buffer[1000];

    itoa(2147, buffer);
    printf("%s\n", buffer);
    return 0;
}
