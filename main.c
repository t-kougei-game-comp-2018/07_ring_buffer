#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10


typedef struct
{
	int *data;
	int front, rear;
}queue;



//いっぱいかどうか
int isFull(queue *q)
{		//末尾のつぎが先頭のとき		先頭が0で末尾が指定サイズまで達しているとき（末尾の次が先頭)
	if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == BUFFER_SIZE - 1)) return 1;
	return 0;
}

//からかどうか
int isEmpty(queue *q)
{
	if (q->front == -1) return 1;
	return 0;
}

//キューへの追加
void enqueue(queue *q, int value)
{
	if (isFull(q)) return; //末尾の次が先頭（バッファいっぱい）のときはなんもしねえ



	if (q->front == -1)
	{
		q->front = q->rear = 0;
	}
	else
	{
		if (q->rear == BUFFER_SIZE - 1)
		{
			q->rear = 0;
		}
		else
		{
			q->rear = (q->rear + 1) % BUFFER_SIZE;	//末尾ずらし
		}
	}

	//追加
	q->data[q->rear] = value;

}

//キューからの取出し
void dequeue(queue *q)
{
	if (isEmpty(q)) return; //キューにデータないときなんもしねえ

	int num = q->data[q->front];
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		q->front = (q->front + 1) % BUFFER_SIZE; //先頭変更
	}

	printf("%d\n", num); //とりだすものを呟く

}

//一覧を表示
void show(queue *q)
{
	if (q->front == q->rear) //キューにデータがないときは改行だけしよう
	{
		printf("\n");
		return;
	}
	int i;
	for (i = q->front; i != q->rear; i = (i + 1) % BUFFER_SIZE)
	{
		printf("%d ", q->data[i]);
	}
	printf("%d ", q->data[i]);
	printf("\n");

}

//しょきか
void initQueue(queue *q)
{
	q->data = (int *)malloc(sizeof(int) * BUFFER_SIZE);
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		q->data[i] = 0;
	}
	q->front = -1;
	q->rear = -1;
}


int main(int argc, char *argv[])
{
	char str[7];
	queue *qp = (queue *)malloc(sizeof(queue));
	initQueue(qp);

	while (fgets(str, sizeof(str), stdin))
	{
		int number = atoi(str);

		//一覧出力
		if (number == 0)
		{
			show(qp);
		}

		//データ取出し
		else if (number == -1)
		{
			dequeue(qp);
		}

		//データ追加
		else
		{
			enqueue(qp, number);
		}

	}



	free(qp);
	return 0;
}