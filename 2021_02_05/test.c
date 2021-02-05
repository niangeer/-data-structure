#include <stdio.h>

//������������ arr ���ҳ�������С�� k ������
//����:
//����4��5��1��6��2��7��3��8��8�����֣�����С��4��������1��2��3��4��
//
//ʾ��1��
//���룺arr = [3, 2, 1], k = 2
//�����[1, 2] ����[2, 1]

//Note: The returned array must be malloced, assume caller calls free().

void AdjustDown(int *a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child<n)
	{
		if (child + 1<n && a[child + 1]>a[child])
		{
			child++;
		}
		if (a[child]>a[parent])
		{
			int tmp = a[parent];
			a[parent] = a[child];
			a[child] = tmp;

			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){

	*returnSize = k;
	if (0 == k)
	{
		return NULL;
	}

	int *retArr = (int *)malloc(sizeof(int)*k);
	if (NULL == retArr)
	{
		exit(-1);
	}
	//��k��Ԫ�ص��붯̬���ٵ�����
	for (int i = 0; i<k; i++)
	{
		retArr[i] = arr[i];
	}
	//��k��Ԫ�صĴ��
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(retArr, k, i);
	}
	//��ԭ�����е�k+1��Ԫ�ؿ�ʼ�ڶѶ��Ƚϣ�С�����滻
	for (int i = k; i<arrSize; i++)
	{
		if (retArr[0]>arr[i])
		{
			retArr[0] = arr[i];
			AdjustDown(retArr, k, 0);
		}
	}

	return retArr;
}