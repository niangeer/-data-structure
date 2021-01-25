#include "queue.h"

//队列：先进先出

void Test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);

	printf("%d ", QueueFront(&q));
	QueuePop(&q);

	QueuePush(&q, 3);
	QueuePush(&q, 4);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestory(&q);
}

int main()
{
	Test();
	system("pause");
	return 0;
}