#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10


typedef struct
{
	int *data;
	int front, rear;
}queue;



//�����ς����ǂ���
int isFull(queue *q)
{		//�����̂����擪�̂Ƃ�		�擪��0�Ŗ������w��T�C�Y�܂ŒB���Ă���Ƃ��i�����̎����擪)
	if ((q->front == q->rear + 1) || (q->front == 0 && q->rear == BUFFER_SIZE - 1)) return 1;
	return 0;
}

//���炩�ǂ���
int isEmpty(queue *q)
{
	if (q->front == -1) return 1;
	return 0;
}

//�L���[�ւ̒ǉ�
void enqueue(queue *q, int value)
{
	if (isFull(q)) return; //�����̎����擪�i�o�b�t�@�����ς��j�̂Ƃ��͂Ȃ�����˂�



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
			q->rear = (q->rear + 1) % BUFFER_SIZE;	//�������炵
		}
	}

	//�ǉ�
	q->data[q->rear] = value;

}

//�L���[����̎�o��
void dequeue(queue *q)
{
	if (isEmpty(q)) return; //�L���[�Ƀf�[�^�Ȃ��Ƃ��Ȃ�����˂�

	int num = q->data[q->front];
	if (q->front == q->rear) {
		q->front = -1;
		q->rear = -1;
	}
	else
	{
		q->front = (q->front + 1) % BUFFER_SIZE; //�擪�ύX
	}

	printf("%d\n", num); //�Ƃ肾�����̂�ꂭ

}

//�ꗗ��\��
void show(queue *q)
{
	if (q->front == q->rear) //�L���[�Ƀf�[�^���Ȃ��Ƃ��͉��s�������悤
	{
		printf("\n");
		return;
	}
	int i, c = 0;
	for (i = q->front; i != q->rear; i = (i + 1) % BUFFER_SIZE)
	{
		if (c == 0)
		{
			printf("%d", q->data[i]);
			c++;
		}
		else
		{
			printf(",%d", q->data[i]);
		}
	}
	printf(",%d\n", q->data[i]);
}

//���傫��
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

		//�ꗗ�o��
		if (number == 0)
		{
			show(qp);
		}

		//�f�[�^��o��
		else if (number == -1)
		{
			dequeue(qp);
		}

		//�f�[�^�ǉ�
		else
		{
			enqueue(qp, number);
		}

	}



	free(qp);
	return 0;
}