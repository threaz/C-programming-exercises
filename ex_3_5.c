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

int itob(int n, char s[], int b)
{
    int i, sign;

    if(n < 0)
    {
        sign = -1;
        n = -n;
    }
    else sign = 1;

    if(b > 0 && b <= 10){
        for(i = 0; n > 0; ++i)
        {
            s[i] = (n % b) + 48;
            n /= b;
        }
    }
    else if(b < 0) return 0;
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';

    reverse(s);
    return 1;
}

int main()
{
    char buffer[100];
    itob(165, buffer, 10);
    printf("%s\n", buffer);
    return 0;
}

