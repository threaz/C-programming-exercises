#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct listElem
{
  int data;
  struct listElem *next;
};

struct list
{
  struct listElem *head;
};

struct tnode 
{
  char *word;
  struct list   index;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(struct tnode *p, char *w, int line_num);
void          treeprint(struct tnode *);
int           getword(char *, int);

void          push(struct list *p, int data);
void          display(struct list *p);

bool          is_excessive(char *w);
#define MAXWORD 100
int line_num;

int main()
{
  int cond;
  char word[MAXWORD];
  struct tnode *root;

  line_num = 1;
  root = NULL;
  while((cond = getword(word, MAXWORD)) != EOF)
    {
      if(isalpha(word[0]))
	if(!is_excessive(word))
	  root = addtree(root, word, line_num);
    }
  treeprint(root);
  return 0;
}

void push(struct list *p, int data)
{
  struct listElem *tmp, *ptr;
  
  if(p->head == NULL)
    {
      tmp = malloc(sizeof(struct listElem));
      tmp->data = data;
      tmp->next = NULL;
      
      p->head = tmp;
    }
  else
    {
      for(ptr=p->head; ptr->next != NULL; ptr = ptr->next)
	;
      tmp = malloc(sizeof(struct listElem));
      tmp->data = data;
      tmp->next = NULL;
      
      ptr->next = tmp;
    }
}

void display(struct list *p)
{
  struct listElem *ptr;
  
  if(p == NULL || p->head == NULL)
    return;

  for(ptr=p->head; ptr != NULL; ptr = ptr->next)
    printf("%d, ", ptr->data);
  printf("\n");
}


int getword(char * word, int max)
{
  int c, prev;
  char * w = word;
  
  do
    {
      c = getchar();
      if(c == '\n')
	++line_num;
    }while(isspace(c));

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

int myComp(const void *a, const void *b)
{
  return strcmp(a, *(const char **)b);
}

bool is_excessive(char *w)
{
  char *excessive_words[] = 
    {
      "lub",
      "ten",    
    };
  int n_elem = sizeof(excessive_words)/sizeof(char *);

  return bsearch(w, excessive_words, n_elem, 
		 sizeof(excessive_words[0]), myComp);

}

struct tnode *talloc(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

struct tnode *addtree(struct tnode *p, char *w, int line_num)
{
  int cond;
 
  if(p == NULL)
    {
      p = talloc();
      p->word = strdup(w);
      push(&(p->index), line_num);
      p->left = p->right = NULL;
   }
  else if((cond = strcmp(w, p->word)) < 0)
    p->left = addtree(p->left, w, line_num);
  else if(cond > 0)
    p->right = addtree(p->right, w, line_num);

  return p;
}

void treeprint(struct tnode *p)
{
  if(p != NULL)
    {
      treeprint(p->left);
      printf("\t%s ",p->word);
      display(&(p->index));
      treeprint(p->right);
    }
}
