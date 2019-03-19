#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *array;
	size_t used;
	size_t size;
} Array;

void initArray(Array *a, size_t initialSize){
	a->array = (int *)malloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}

void insertArray(Array *a, int element){
	if(a->used == a->size){
		a->size *= 2;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a){
	free(a->array);
	a->array = NULL;
	a->used = 0;
	a->size = 0;
}

int main(){

	FILE* file = fopen("input1.txt","r");
	int i = 0;
	long total = 0;

	Array a;
	Array values;

	initArray(&a, 10);
	initArray(&values, 10);

	insertArray(&values, 0); //start with 0

	fscanf(file, "%d", &i);

	while(!feof(file)){
		total += i;
		insertArray(&a, i);
		insertArray(&values, total);
		fscanf(file, "%d", &i);
	}
	fclose(file);

	int fd = 0;
	while(fd == 0){
		for(int n = 0; n < a.size; n++){
			total += a.array[n];
			for(int m = 0; m < values.size; m++){
				if(values.array[m] == total){
					printf("Answer is %lu\n", total);
				    return 0;	
				}
			}
			insertArray(&values, total);
		}
	}


	return 0;
}

