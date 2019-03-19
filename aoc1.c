#include <stdio.h>

int main(){

	FILE* file = fopen("input1.txt","r");
	int i = 0;
	long total = 0;

	fscanf(file, "%d", &i);
	while(!feof(file)){
		total += i;
		fscanf(file, "%d", &i);
	}
	fclose(file);
	printf("total: %ld\n", total);
	return 0;
}
