#include <heap.h>
#include <stdlib.h>
#include <stdio.h>

#define ROOT 0

/////////////////////////////////////////////////////
void testingordenation(int *vector, int len){

	for(int i=0, j=1; j<len; i++, j++)
		if(vector[j] < vector[i]){
			printf("Vector is not ordenated\n");
			exit(EXIT_FAILURE);
		}
	
	for(int i=0; i<len; i++)
		printf("%d " ,vector[i]);

	printf("\nVector is ordenated\n");
}
/////////////////////////////////////////////////////
void destroyheap(MIN_HEAP *heap){

	if(!heap) return;
	if(heap->vector)free(heap->vector);
	free(heap);
}
/////////////////////////////////////////////////////
void swap(int *vector, int A, int B){

	int aux = vector[A];
	vector[A] = vector[B];
	vector[B] = aux;
}
//////////////////////////////////////////////////////
void fixheap2(MIN_HEAP *heap, int node){

	int father = node;
	int aux = father;
	int son;

	for(int i=1; i<=heap->d; i++){
		son = heap->d*father+i;
		if(son < heap->counter && heap->vector[father] > heap->vector[son] && 
			heap->vector[aux] > heap->vector[son]) aux = son;
	}

	if(aux != node){
		swap(heap->vector, father, aux);
		fixheap2(heap, aux);
	}
	
}
//////////////////////////////////////////////////////
int removeheap(MIN_HEAP *heap){

	int item = heap->vector[ROOT];

	swap(heap->vector, ROOT, heap->counter-1);
	heap->vector = (int *) realloc(heap->vector, sizeof(int)*(heap->counter-1));
	heap->counter--;
	fixheap2(heap, ROOT);

return item;
}
//////////////////////////////////////////////////////
void fixheap(MIN_HEAP *heap){

	int son = heap->counter-1;
	int father = (son-1)/heap->d;
	int aux = 0;

	while(son != ROOT && heap->vector[son] < heap->vector[father]){
			swap(heap->vector, son, father);
			aux = (father-1)/heap->d;
			son = father;
			father = aux;
	}
}
////////////////////////////////////////////////////
void insertheap(MIN_HEAP *heap, int elem){

	heap->vector = (int *) realloc(heap->vector, (heap->counter+1)*sizeof(int));
	heap->vector[heap->counter++] = elem;
	fixheap(heap);
}
////////////////////////////////////////////////////
MIN_HEAP *createheap(int d){

	MIN_HEAP *heap = (MIN_HEAP *)calloc(1, sizeof(MIN_HEAP));
	heap->d = d;

return heap;
}
