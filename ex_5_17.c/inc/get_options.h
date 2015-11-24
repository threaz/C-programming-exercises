#ifndef GET_OPTIONS_H
#define GET_OPTIONS_H

extern bool numeric;
extern bool reverse;
extern bool fold;
extern bool dict;
extern int  to;
extern int  from;

int get_options(int argc, char ** argv);

#endif
