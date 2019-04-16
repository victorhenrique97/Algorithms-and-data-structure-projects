#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct MIN_HEAP{
	int *vector;
	int counter;
	int d;
}MIN_HEAP;

MIN_HEAP *createheap(int);

void insertheap(MIN_HEAP *, int);

int removeheap(MIN_HEAP *);

void destroyheap(MIN_HEAP *);

void testingordenation(int *, int);

#endif