#include <stdio.h>
#include <Windows.h>

//给定一个整数数组nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
//
//示例 ：
//输入 ： [1, 2, 1, 3, 2, 5]
//输出 ： [3, 5]

int* singleNumber(int* nums, int numsSize, int* returnSize){
	//ret与所有数异或，得出结果ret==x1^x2;x1与x2为数组中两个只出现一次的数
	int ret = 0;
	for (int i = 0; i<numsSize; i++)
	{
		ret ^= nums[i];
	}
	//x1、x2不同所以异或后的值肯定不为0，找出比特位为1的值分离出x1与x2
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
	//进行分离，第M位为1的为一组，第M位为0的为1组
	int x1 = 0, x2 = 0;
	for (int i = 0; i<numsSize; i++)
	{
		//第一组为x1与其余出现过两次的数
		if (nums[i] & (1 << m))
		{
			x1 ^= nums[i];
		}
		//第二组为x2与其余出现过两次的数
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
