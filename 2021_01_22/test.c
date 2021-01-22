#include <stdio.h>

//对于非负整数 X 而言，X 的数组形式是每位数字按从左到右的顺序形成的数组。
//例如，如果 X = 1231，那么其数组形式为 [1,2,3,1]。
//给定非负整数 X 的数组形式 A，返回整数 X + K 的数组形式。
//
//示例1：
//输入：A = [1, 2, 0, 0], K = 34
//输出：[1, 2, 3, 4]
//解释：1200 + 34 = 1234
//
//示例2：
//输入：A = [2, 7, 4], K = 181
//输出：[4, 5, 5]


//解释：274 + 181 = 455

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	//先求出K的长度
	int KSize = 0, KCopy = K;
	while (KCopy)
	{
		KCopy /= 10;
		KSize++;
	}
	//取长度较长的赋予len
	int len = ASize > KSize ? ASize : KSize;
	//创建一个len+1的数组用来放置相加之后的数
	int *dst = (int *)malloc(sizeof(int)*(len + 1));
	//len 的下标
	int i = 0;
	//A 的下标
	int cur = ASize - 1;
	//进位
	int nextnum = 0;
	//循环len次
	while (len--)
	{
		int a = 0;
		if (cur >= 0)
		{
			a = A[cur];
		}
		//获得求和
		dst[i] = a + (K % 10) + nextnum;
		//判断是否进位
		if (dst[i] > 9)
		{
			dst[i] -= 10;
			nextnum = 1;
		}
		else
		{
			nextnum = 0;
		}

		K /= 10; i++; cur--;
	}
	//若两数长度相等，循环出来后进位可能为1
	if (1 == nextnum)
	{
		dst[i] = 1;
		i++;
	}
	//逆置数组
	int left = 0; int right = i - 1;
	while (left<right)
	{
		int tmp = dst[left];
		dst[left] = dst[right];
		dst[right] = tmp;
		left++;
		right--;
	}

	*returnSize = i;
	return dst;
}