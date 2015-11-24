#include <stdio.h>

char * squeeze(char s[], char pattern[])
{
    int i; /* position in pattern */
    int j; /* position in s[] */
    int k; /* position in s[] */

    for(i = 0; pattern[i] != '\0'; ++i)
        {
            for(j = 0, k = 0; s[j] != '\0'; ++j)
            if(s[j] != pattern[i])
                s[k++] = s[j];
            s[k] = '\0';
        }

    return s;
}

int main()
{
    char buffer[100];

    while(scanf("%s", buffer))
        printf("%s\n", squeeze(buffer, "Lam"));

    return 0;
}
