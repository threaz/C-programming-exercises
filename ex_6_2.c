#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

#define YES 1
#define NO  0

#define MAXCMP 6

struct tnode 
{
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w, int max, int *found);
void          treeprint(struct tnode *);
int           getword(char *, int);
int           myComp(char * s, struct tnode *p, int num, int *found);

int found;

int main(int argc, char ** argv)
{
  char word[MAXWORD];
  struct tnode *root;
  int num;

  found = NO;
  root = NULL;

  num = (argc == 2) ? atoi(*++argv + 1) : MAXCMP;
    
  while(getword(word, MAXWORD) != EOF)
    {
      if(isalpha(word[0]))	
	root = addtree(root, word, num, &found);
      found = NO;
    }
  
  treeprint(root);
  return 0;
}

int getword(char * word, int max)
{
  int c, prev;
  char * w = word;

  while(isspace(c = getchar()))
    ;

  if(c != EOF)
    *w++ = c;

  if(!isalpha(c) && c != '/' && c != '_' && c != '\"' && c != '#') {
    *w = '\0';
    return c;
  }
  
  if(c == '/' && (*w = getchar()) == '*') /* discard comments */
    {
      prev = ' ';
      while(prev != '*' || c != '/')
	{
	  prev = c;
	  c = getchar();
	}	

      return '/';
    }
  else if(c == '\"') /* discard strings */
    {
      c == ' ';
      while((c = getchar()) != '\"')
	;
      
      return '\"';
    }
  else if(c == '#')
    {
      while((c = getchar()) != '\n')
	;
      return '#';
    }
  
  for( ; --max > 0; w++) {
    if(!isalnum(*w = getchar()) && *w != '_') {
      ungetc(*w, stdin);
      break;
    }
  }
  
  *w = '\0';
  return word[0];
}


struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

int myComp(char * s, struct tnode *p, int num, int *found)
{
  int i;
  char *t = p->word;

  for(i = 0; *s == *t; ++i, ++s, ++t)
    if(*s == '\0')
      return 0;

  if(i >= num)
    {
      *found = YES;
      p->match = YES;
    }
  
  return *s - *t;
}

struct tnode *addtree(struct tnode *p, char *w, int max, int *found)
{
  int cond;
  
  if(p == NULL)
    {
      p = talloc();
      p->word = strdup(w);
      p->match = *found;
      p->left = p->right = NULL;
    }
  else if((cond = myComp(w, p, max, found)) < 0)
    p->left = addtree(p->left, w, max, found);
  else if(cond > 0)
    p->right = addtree(p->right, w, max, found);

  return p;
}

void treeprint(struct tnode *p)
{
  if(p != NULL)
    {
      treeprint(p->left);
      if(p->match) 
	printf("\t%s\n",p->word);
      treeprint(p->right);
    }
}

/*
  Is valid for only one-word type names;

  Returns:
  EOF: when end of file
  > 0: not variable name
  0  : variable name
 */
/*
int get_variable_name(char * store, int n)
{
  int cond;
  int i;
  char * vartype_tab[] = 
    {
      "double",
      "float",
      "int",
      "long",
      "short",
      "unsigned",p
    };
  
  size_t vartab_size = (sizeof (vartype_tab)) / (sizeof(char *));
  if((cond = getword(store, MAXWORD)) == EOF)
    return EOF;

  for(i = 0; i < (int)vartab_size; ++i)
    if(strcmp(vartype_tab[i], store) == 0)
      {	
	en_cond = YES;
	return 10;
      }
  
  if(en_cond == YES) 
    {
      if(cond == ';' || cond == '(')
	{
	  en_cond = NO;
	  return 10;
	}
	
      return 0;
    }

  else 
    return 10;    
}
*/
