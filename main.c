#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
	int front, rear, count, size;
	int *buff;
} Queue;


Queue *make_queue(int n)
{
	Queue *que = malloc(sizeof(Queue));
	if (que != NULL) {
		que->front = 0;
		que->rear = 0;
		que->count = 0;
		que->size = n;
		que->buff = malloc(sizeof(int) * n);
		if (que->buff == NULL) {
			free(que);
			return NULL;
		}
	}
	return que;
}



bool is_full(Queue *que)
{
	return que->count == que->size;
}


bool is_empty(Queue *que)
{
	return que->count == 0;
}


bool enqueue(Queue *que,int x)
{
	if (is_full(que)) return false;
	que->buff[que->rear++] = x;
	que->count++;
	if (que->rear == que->size)
		que->rear = 0;
	return true;
}


int dequeue(Queue *que, bool *err)
{
	if (is_empty(que)) {
		*err = false;
		return 0;
	}
	int x = que->buff[que->front++];
	que->count--;
	*err = true;
	if (que->front == que->size)
		que->front = 0;
	return x;
}


int main(int argc, char *argv[])
{
	Queue *que = make_queue(10);
	bool err;
	int i,j;
	char str[100];

	while (fgets(str, sizeof(str), stdin)) {
		i = atoi(str);

			if (is_full(que) == 0) {
				if (1 <= i && i <= 100) {
					enqueue(que, i);
				}

			}
		

			if (i == -1) {
				printf("%d\n", dequeue(que, &err));
				for (j = 0; j < que->rear - 1; j++) {
					que->buff[j] = que->buff[j + 1];
				}
				que->rear--;
			}

		if (i == 0) {
			for (j = 0; j < que->rear; j++) {
				printf("%d", que->buff[j]);
				if (j<que->rear-1) {
					printf(",");
				}
			}
			printf("\n");
		}
	}
		return 0;
	
}
