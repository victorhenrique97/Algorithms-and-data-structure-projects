#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <heap.h>

enum{
	PROGNAME,
	D,
	NELEMENTS,
	MIN_VALUE,
	MAX_VALUE,
	NARGS
};

int main(int argc, char *argv[]){

	MIN_HEAP *heap = NULL;
	int *vector = NULL;
	int counter = 0;

	srand(time(NULL));
	
	if(argc != NARGS){
		printf("Usage %s d nelements minvalue maxvalue\n", argv[PROGNAME]);
	return -1;
	}

	if(!atoi(argv[D])){
		printf("Usage d higher them zero\n");
	return -1;
	}

	if(!atoi(argv[NELEMENTS])){
		printf("Usage nelements higher them zero\n");
	return -1;
	}

	heap = createheap(atoi(argv[D]));

	for(int i=0; i<atoi(argv[NELEMENTS]); i++)
		insertheap(heap, rand()%(atoi(argv[MAX_VALUE])-atoi(argv[MIN_VALUE])+1) + atoi(argv[MIN_VALUE]));
	
	for(int i=0; i<atoi(argv[NELEMENTS]); i++){
		vector = (int *) realloc(vector, sizeof(int)*(counter+1));
		vector[counter++] = removeheap(heap);
	}
	testingordenation(vector, counter);
	free(vector);
	destroyheap(heap);

return 0;
}