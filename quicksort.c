#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAB_SIZE 100000

void swap(int s[], int i, int j);
void quicksort(int s[], int, int);
void selectionsort(int s[], int n);

int main()
{
  int tab[TAB_SIZE];
  int i;
  clock_t prog_exec_time;
 
  srand(time(NULL));

  /*
  puts("Przed posortowaniem: ");
  */
  for(i = 0; i < TAB_SIZE; ++i)
    {
      tab[i] = rand() % 1000;
      //printf("%d ", tab[i]);
    }

  prog_exec_time = clock();

  //selectionsort(tab, TAB_SIZE);
  quicksort(tab, 0, TAB_SIZE - 1);
  prog_exec_time = clock() - prog_exec_time;


  puts("Po posortowaniu: ");
  for(i = 0; i < TAB_SIZE; ++i)
    printf("%d ", tab[i]);

  putchar('\n');


  printf("Sortowanie odbylo sie w czasie: %fs\n",
	 ((float)prog_exec_time)/CLOCKS_PER_SEC);
  return 0;
}

void swap(int s[], int i, int j)
{
  int temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

void selectionsort(int s[], int n)
{
  int i, k;
  int min;
  
  for(i = 0; i < n; ++i)
    {
      for(k = i, min = k; k < n; ++k)
	{
	  if(s[k] < s[min])
	    min = k;
	}
      swap(s, min, i);
    }
}

void quicksort(int s[], int left, int right)
{
  int i, k;
  int key;

  if(left >= right)
    /* finish */
    return;

  key = (left + right) / 2;
  swap(s, key, left);
  
  for(i = k = left + 1; i <= right; ++i)
    {
      if(s[i] < s[left])
	{
	  swap(s, i, k);
	  ++k;
	}
    }
  swap(s, left, key = k - 1);
  quicksort(s, left, key - 1);
  quicksort(s, key + 1, right);
  
}
