#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct tnode 
{
  char *word;
  int n_times;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w);
void          treeprint(struct tnode *);
int           getword(char *, int);

void          treestore(struct tnode *p);
void          sortlist(void);
void          printtreestore(void);

#define MAXWORD 100
#define MAXTAB  200

struct tnode * tab_elem[MAXTAB];
int nth_node = 0;

int main()
{
  char word[MAXWORD];
  struct tnode *root;
  
  root = NULL;
  while(getword(word, MAXWORD) != EOF)
    {
      if(isalpha(word[0]))
	root = addtree(root, word);
    }
  
  treestore(root);
  sortlist();
  printtreestore();
  
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

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;
 
  if(p == NULL)
    {
      p = talloc();
      p->n_times = 1;
      p->word = strdup(w);
      p->left = p->right = NULL;
   }
  else if((cond = strcmp(p->word, w)) == 0)
    ++p->n_times;
  else if(cond < 0)
    p->left = addtree(p->left, w);
  else if(cond > 0)
    p->right = addtree(p->right, w);

  return p;
}

void treeprint(struct tnode *p)
{
  if(p != NULL)
    {
      treeprint(p->left);
      printf("[+] %d -> %s\n", p->n_times, p->word);
      treeprint(p->right);
    }
}

void treestore(struct tnode *p)
{
  if(p != NULL)
    {
      treestore(p->left);
      tab_elem[nth_node++] = p;
      treestore(p->right);
    }
}

int myComp(const void *a, const void *b, void *thuckIn)
{
  struct tnode *x, *y;
  x = *(struct tnode * const *)a;
  y = *(struct tnode * const *)b;
  int thuck = *((int *)thuckIn);
  
  if(thuck == 0)
    {
      if(x->n_times == y->n_times)
	return 0;
      else if(x->n_times < y->n_times)
	return -1;
      else if(x->n_times > y->n_times)
	return 1;
    }
  else
    {
      if(x->n_times == y->n_times)
	return 0;
      else if(x->n_times > y->n_times)
	return -1;
      else if(x->n_times < y->n_times)
	return 1;      
    }
}

void sortlist(void)
{
  int thuck = 1;
  qsort_r(tab_elem, nth_node, sizeof(struct tnode *), myComp, &thuck);
}

void printtreestore(void)
{
  int i;
  for(i = 0; i < nth_node; ++i)
    printf("\t%3d\t%s\n", tab_elem[i]->n_times, tab_elem[i]->word);
}
