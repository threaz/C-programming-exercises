#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "get_options.h"

#define PROPER_INV "error: sort_string_num [-dfnr] [-from] [+to]\n"

int get_options(int argc, char ** argv)
{
  int ch;
  int c;
  
  while(--argc > 0) {
    if((ch = (*++argv)[0]) != '-' && ch != '+') {
      printf(PROPER_INV);
      return -1;
    }
    
    while(isalpha(c = *++argv[0])){
	switch(c){
	case 'd':
	  dict = true;
	  break;
	case 'f':
	  fold = true;
	  break;
	case 'n':
	  numeric = true;
	  break;
	case 'r':
	  reverse = true;
	  break;
	default:
	  printf(PROPER_INV);
	  return -1;	  
	}
    }

    if(isdigit(c)){
      if(ch == '+')
	from = atoi(argv[0]);
      else if(ch == '-')
	to = atoi(argv[0]);
    }
    
  } /* while */

  if(argc || from > to){
    printf(PROPER_INV);
    return -1;
  }    
    
  
  return 0;
}      
