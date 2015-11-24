#include <stdio.h>
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

int main()
{
  int i;
  install("#define", "10");
  install("#define1", "20");
  
  for(i = 0; i < HASHSIZE; ++i)
    if(hashtab[i] != NULL)
      printf("%s, %s\n", hashtab[i]->name, hashtab[i]->defn);
  
  undef("#define");

  for(i = 0; i < HASHSIZE; ++i)
    if(hashtab[i] != NULL)
      printf("%s, %s\n", hashtab[i]->name, hashtab[i]->defn);
  
  return 0;
}
