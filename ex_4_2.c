#include <stdio.h>
#include <ctype.h>

double atof(char * arr);

int main()
{
    char buff[12];

    scanf("%s", buff);

    printf("%f\n", atof(buff));
    return 0;
}

double atof(char * arr)
{
    int sign, i;
    double val, power;

    i = 0;
    while(isspace(arr[i++]))
        continue;

    sign = (arr[i++] == '-') ? -1 : 1;

    val = 0;
    while(isdigit(arr[i]))
    {
        val = val * 10 + (arr[i] - '0');
        i++;
    }

    if(arr[i++] == '.') power = 1;

    while(isdigit(arr[i]))
    {
        val = val * 10 + (arr[i] - '0');
        power *= 10;
        i++;
    }

    return sign * val / power;
}
