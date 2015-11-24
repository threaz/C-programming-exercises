#ifndef GETLINE_H
#define GETLINE_H

#include <stdio.h>

int getline(char tZnakow[], int dlug)
{
	int i;
	int ch;
    enum loop {NO, YES}okloop;
	 // for(i = 0; (ch = getchar()) != EOF && ch != '\n' && i < dlug - 1; ++i)
    i = 0;
    okloop = YES;
    while(okloop != NO)
    {
        if((ch = getchar()) == EOF)
            okloop = NO;
        else if(i >= dlug - 1)
            okloop = NO;
        else if(ch == '\n')
            okloop = NO;
        else
        {
            tZnakow[i] = ch;
            ++i;
        }

    }


	if(ch == '\n')
	{
		tZnakow[i] = '\n';
		++i;
	}
	tZnakow[i] = '\0';
	return i;
}

#endif
