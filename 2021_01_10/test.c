#include <stdio.h>
#include <Windows.h>

//����һ����������nums������ǡ��������Ԫ��ֻ����һ�Σ���������Ԫ�ؾ��������Ρ� �ҳ�ֻ����һ�ε�������Ԫ�ء�
//
//ʾ�� ��
//���� �� [1, 2, 1, 3, 2, 5]
//��� �� [3, 5]

int* singleNumber(int* nums, int numsSize, int* returnSize){
	//ret����������򣬵ó����ret==x1^x2;x1��x2Ϊ����������ֻ����һ�ε���
	int ret = 0;
	for (int i = 0; i<numsSize; i++)
	{
		ret ^= nums[i];
	}
	//x1��x2��ͬ���������ֵ�϶���Ϊ0���ҳ�����λΪ1��ֵ�����x1��x2
	int m = 0;
	while (m<32)
	{
		if (ret & (1 << m))
		{
			break;
		}
		else
		{
			m++;
		}
	}
	//���з��룬��MλΪ1��Ϊһ�飬��MλΪ0��Ϊ1��
	int x1 = 0, x2 = 0;
	for (int i = 0; i<numsSize; i++)
	{
		//��һ��Ϊx1��������ֹ����ε���
		if (nums[i] & (1 << m))
		{
			x1 ^= nums[i];
		}
		//�ڶ���Ϊx2��������ֹ����ε���
		else
		{
			x2 ^= nums[i];
		}
	}
	int* retArr = (int *)malloc(sizeof(int)* 2);
	retArr[0] = x1;
	retArr[1] = x2;
	*returnSize = 2;
	return retArr;
}
