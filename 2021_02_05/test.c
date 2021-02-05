#include <stdio.h>

//输入整数数组 arr ，找出其中最小的 k 个数。
//例如:
//输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
//
//示例1：
//输入：arr = [3, 2, 1], k = 2
//输出：[1, 2] 或者[2, 1]

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
	//将k个元素导入动态开辟的数组
	for (int i = 0; i<k; i++)
	{
		retArr[i] = arr[i];
	}
	//建k个元素的大堆
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(retArr, k, i);
	}
	//将原数组中第k+1个元素开始于堆顶比较，小于则替换
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