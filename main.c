#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// キューの定義
typedef struct {
	int front, rear, count, size;
	int *buff;
} Queue;

// キューの生成
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


// キューは満杯か
bool is_full(Queue *que)
{
	return que->count == que->size;
}

// キューは空か
bool is_empty(Queue *que)
{
	return que->count == 0;
}

// データの挿入
bool enqueue(Queue *que,int x)
{
	if (is_full(que)) return false;
	que->buff[que->rear++] = x;
	que->count++;
	if (que->rear == que->size)
		que->rear = 0;
	return true;
}

// データを取り出す
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
	Queue *que = make_queue(11);
	bool err;
	int i,j,b=0;
	char str[100];

	while (fgets(str, sizeof(str), stdin)) {
		i = atoi(str);

			if (b<10) {
				if (1 <= i && i <= 100) {
					enqueue(que, i);//入力
					b++;
				}

			}
		

			if (i == -1) {
				printf("%d\n", dequeue(que, &err));//取り出し
				for (j = 0; j < que->rear - 1; j++) {
					que->buff[j] = que->buff[j + 1];
				}
				b--;
				que->rear--;
			}

		if (i == 0) {
			for (j = 0; j < que->rear; j++) {
				printf("%d", que->buff[j]);//表示
				if (j<que->rear-1) {
					printf(",");
				}
			}
			printf("\n");
		}
	}
		return 0;
	
}
