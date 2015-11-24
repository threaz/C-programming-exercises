#ifndef CALC_H
#define CALC_H

#define NUMBER '0'
#define WORD 'x'

int getch(void);
void ungetch(int);
void ungetch_string(char s[]);
int getop(char s[]);

void push(double f);
double pop(void);
void clear(void);
#endif
