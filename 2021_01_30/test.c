#include <stdio.h>
#include <stdbool.h>

//������ѭ������ʵ�֡� ѭ��������һ���������ݽṹ��
//��������ֻ��� FIFO���Ƚ��ȳ���ԭ���Ҷ�β�������ڶ���֮�����γ�һ��ѭ������Ҳ����Ϊ�����λ���������
//
//ѭ�����е�һ���ô������ǿ��������������֮ǰ�ù��Ŀռ䡣
//��һ����ͨ�����һ��һ���������ˣ����ǾͲ��ܲ�����һ��Ԫ�أ�
//��ʹ�ڶ���ǰ�����пռ䡣����ʹ��ѭ�����У�������ʹ����Щ�ռ�ȥ�洢�µ�ֵ��
//
//���ʵ��Ӧ��֧�����²�����
//
//1��MyCircularQueue(k) : �����������ö��г���Ϊ k ��
//2��Front : �Ӷ��׻�ȡԪ�ء��������Ϊ�գ����� - 1 ��
//3��Rear : ��ȡ��βԪ�ء��������Ϊ�գ����� - 1 ��
//4��enQueue(value) : ��ѭ�����в���һ��Ԫ�ء�����ɹ������򷵻��档
//5��deQueue() : ��ѭ��������ɾ��һ��Ԫ�ء�����ɹ�ɾ���򷵻��档
//6��isEmpty() : ���ѭ�������Ƿ�Ϊ�ա�
//7��isFull() : ���ѭ�������Ƿ�������
//
//ʾ��1��
//
//MyCircularQueue circularQueue = new MyCircularQueue(3); // ���ó���Ϊ 3
//circularQueue.enQueue(1); //����true
//circularQueue.enQueue(2); //����true
//circularQueue.enQueue(3); //����true
//circularQueue.enQueue(4); //���� false����������
//circularQueue.Rear(); //���� 3
//circularQueue.isFull(); //����true
//circularQueue.deQueue(); //����true
//circularQueue.enQueue(4);//����true
//circularQueue.Rear(); //���� 4

typedef struct {
	int *_a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_a = (int *)malloc(sizeof(int)*(k + 1));
	q->_front = q->_rear = 0;
	q->_k = k;

	return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}
	obj->_a[obj->_rear] = value;
	obj->_rear++;
	obj->_rear %= (obj->_k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}
	obj->_front++;
	obj->_front %= (obj->_k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		return obj->_a[obj->_front];
	}

}

int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}
	else
	{
		int tail = obj->_rear - 1;
		if (tail == -1)
		{
			tail = obj->_k;
		}
		return obj->_a[tail];
	}
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_a);
	free(obj);
}

/**
* Your MyCircularQueue struct will be instantiated and called as such:
* MyCircularQueue* obj = myCircularQueueCreate(k);
* bool param_1 = myCircularQueueEnQueue(obj, value);

* bool param_2 = myCircularQueueDeQueue(obj);

* int param_3 = myCircularQueueFront(obj);

* int param_4 = myCircularQueueRear(obj);

* bool param_5 = myCircularQueueIsEmpty(obj);

* bool param_6 = myCircularQueueIsFull(obj);

* myCircularQueueFree(obj);
*/
