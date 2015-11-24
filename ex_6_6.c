#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct nlist
{
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
  unsigned hashval;
  
  for(hashval = 0; *s != '\0'; ++s)
    hashval = *s + hashval * 31;
  
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
  struct nlist *np;
  
  for(np = hashtab[hash(s)]; np != NULL; np = np->next)
    if(strcmp(s, np->name) == 0)
      return np;

  return NULL;
}

char * get_defn_of_name(char * name)
{
  struct nlist *tmp_ptr = NULL;
  
  tmp_ptr = lookup(name);
  if(tmp_ptr == NULL)
    return NULL;
  
  return tmp_ptr->defn;
}

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;
  
  if((np = lookup(name)) == NULL) /* Nie znaleziono */
    {
      np = (struct nlist *)malloc(sizeof(struct nlist));
      if(np == NULL || (np->name = strdup(name)) == NULL)
	return NULL;
      
      hashval = hash(name);
      np->next = hashtab[hashval];
      hashtab[hashval] = np;
    }
  else                            /* już była */
    free((void *) np->defn);

  if((np->defn = strdup(defn)) == NULL)
    return NULL;
    
  return np;
}

void undef(char *name)
{
  struct nlist *np, *nx;
  unsigned hashval = hash(name);

  if((np = lookup(name)) == NULL)
    return;
  
  if(np == hashtab[hashval])  
      hashtab[hashval] = np->next;
  else
    {
      for(nx = hashtab[hashval]; nx->next != np; nx = nx->next)
	;
      
      nx = np->next;
    }
      free((void *) np->name);
      free((void *) np->defn);
      free((void *) np);
}

int get_word(char * word, int lim);

#define MAXWORD 100
char word[MAXWORD];

int main()
{
  char tmp_string[MAXWORD];
  int ch;

  struct nlist *list_of_defines = NULL;
  while((ch = getchar()) != EOF)
    {
      if(ch == '#')
	{
	  get_word(word, MAXWORD);
	  if(strcmp(word, "define") == 0)
	    {
	      get_word(tmp_string, MAXWORD);
	      get_word(word, MAXWORD);
	      
	      install(tmp_string, word);
	    }
	  else 
	    printf("%s", word);
	}
      else if(isalpha(ch))
	{
	  ungetc(ch, stdin);
	  get_word(word, MAXWORD);
	  
	  printf("%s", ((lookup(word)) ? get_defn_of_name(word) : word));
	}
      else 
	printf("%c", ch);
    }
  
  return 0;
}

int get_word(char * word, int lim)
{
  int c;
  char *w = word;
    
  while(isspace(c = getchar()))
    ;
  if(c != EOF)
    *w++ = c;
  else 
    {
      *w = '\0';
      return c;
    }

  for(; --lim > 0; w++)
    if(! isalnum(*w = getchar()))
      {
	ungetc(*w, stdin);
	break;
      }
  
  *w = '\0';
  return word[0];
}
