#include "getline.h"
#define MAXLINE 1000

int main()
{
    char buffer[MAXLINE];
    int n;

    while((n = getline(buffer, MAXLINE)) > 0)
        puts(buffer);


    return 0;
}
