#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#define BUFFER_SIZE 10


typedef struct{
	int type;
	int amount;
	int unit;
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

void display(item i){
	printf("%d %d %d\n", i.type, i.amount, i.unit);
}

void *thread_produce(void *param){
	item chicken, fries, beef;

        chicken.type = 0;
        chicken.amount = 5;
        chicken.unit = 0;

        fries.type = 1;
        fries.amount = 10;
        fries.unit = 1;

        beef.type = 3;
        beef.amount = 1;
        beef.unit = 3;

		produce(&chicken);
        produce(&fries);
        produce(&beef);
}

void *thread_consume(void *param){
	display(*consume());
	display(*consume());
}

int main(){
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread_produce, NULL);

	pthread_join(tid1, NULL);

	pthread_create(&tid2, NULL, thread_consume, NULL);

	pthread_join(tid2, NULL);
}
