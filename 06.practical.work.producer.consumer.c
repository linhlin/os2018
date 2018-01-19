#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10

typedef struct{
	char *type;
	int amount;
	char *unit;
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i){
	while((first + 1) % BUFFER_SIZE == last){
	}
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
}


item *consume(){
	item *i = malloc(sizeof(item));
	while (first == last){
	}
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	return i;
}

void display(item *i){
	if(i == NULL) return;
	printf("%s %d %s\n", i->type, i->amount, i->unit);
}

int main(){
	item chicken, fries;
	
	chicken.type = "fried";
	chicken.amount = 5;
	chicken.unit = "white";

	fries.type = "grill";
	fries.amount = 10;
	fries.unit = "black";

	produce(&chicken);
	produce(&fries);

	display(consume());
	
	return 0;
}
