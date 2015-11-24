#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *));
void swap(void *v[], int, int);

#endif
