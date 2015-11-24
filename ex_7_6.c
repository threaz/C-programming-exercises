#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 1000

int cmpFiles(FILE * f1, FILE * f2)
{
  char buf1[MAXLINE], buf2[MAXLINE];
  char *fp1, *fp2;
  int n_line = 1;

  do
    {
      fp1 = fgets(buf1, MAXLINE, f1);
      fp2 = fgets(buf2, MAXLINE, f2);
      if(fp1 == NULL && fp2 != NULL) /* skonczyl sie 1 plik */
	{
	  printf("koniec pierwszego pliku w wierszu %d\n", n_line);
	  return -1;
	}
      else if(fp1 != NULL && fp2 == NULL)
	{
	  printf("koniec drugiego pliku w wierszu %d\n", n_line);
	  return -1;
	}

      
      if(strcmp(buf1, buf2) != 0)
	{
	  printf("1:\n%s\n2:\n%s\n", buf1, buf2);
	  return n_line;
	}
      ++n_line;
    }while(fp1 != NULL && fp2 != NULL);
    
  printf("oba pliki sa jednakowe\n");
  return 0;
}

int main(int argc, char ** argv)
{
  FILE * fp1, * fp2;
  char * pr_name = argv[0];
  
  if(argc != 3)
    {
      fprintf(stderr, "%s wywolanie: program nazwa1 nazwa2\n", pr_name);
      exit(1);
    }

  if((fp1 = fopen(*++argv, "r")) == NULL || 
     (fp2 = fopen(*++argv, "r")) == NULL)
    {
      fprintf(stderr, "%s: nie moge otworzyc jednego z plikow\n", pr_name);
      exit(2);
    }
  
  cmpFiles(fp1, fp2);
  
  fclose(fp1);
  fclose(fp2);
  return 0;
}
