#include <stdio.h>

int any(char s1[], char s2[]) /* s2 is a pattern */
{
    int i; /* pos in s1 */
    int j; /* pos in s2 */

    for(j = 0; s2[j] != '\0'; ++j)
    {
        for(i = 0; s1[i] != '\0'; ++i)
            if(s1[i] == s2[j])
            return i;
    }

    return -1;
}

int main()
{
    char buff1[100], buff2[100];

    while(scanf("%s %s", buff1, buff2))
        printf("first letter from %s found in %s is on %d position\n", buff2, buff1, any(buff1, buff2));

    return 0;
}
