#include <stdio.h>
#include <Windows.h>


//   算法效率分析：（1）时间复杂度：不计算时间，计算大概的运行次数
//                 （2）空间复杂度：不计算空间，计算大概定义的变量个数

//大O的渐进表示法：（1）用常数1取代运行时间中的所有加法常数
//                 （2）在修改后的运行次数函数中，只保留最高阶项
//                 （3）如果最高阶项存在且不是1，则去除与这个项目相乘的常数。得到的结果就是大O阶

void Func1(int n)
{
	int count = 0;
	for (int i = 0; i < n; ++i)             //n*n
	{
		for (int j = 0; j < n; ++j)
		{
			count++;
		}
	}
	for (int k = 0; k < 2 * n; ++k)           //2*n
	{
		count++;
	}
	int m = 10;                            //10
	while (m)
	{
		count++;
		m--;
	}                                     //Func1 = N*N + 2N + 10; 
	printf("%d\n", count);                //时间复杂度：O(N*N)
}                                         //空间复杂度：O(1)


void Func2(int n, int m)
{
	int count = 0;
	for (int k = 0; k < m; ++k)          //n
	{
		++count;
	}
	for (int k = 0; k < n; ++k)          //m
	{
		++count;                         //Func2 = M + N
	}                                    //时间复杂度：O(N)
	printf("%d\n", count);               //空间复杂度：0(1)
}

void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)           //最好情况N次
	{                                    //最坏情况F(N) = 1+2+3...+n-1  等差数列，即(n*(n-1))/2
		int flag = 0;                    //时间复杂度：O(N*N)
		for (int j = 0; j < n - 1 - i; j++)//空间复杂度：0(1)
		{
			if (a[j]>a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}


int BinarySearch(int* a, int n, int x)
{
	assert(a);
	int begin = 0;
	int end = n;                                  //时间复杂度
	while (begin <= end)                           //最好情况：O(1)
	{                                              //最坏情况：O(log N)
		int mid = begin + ((end - begin) >> 1);    //O(log N)
		if (a[mid] < x)
			begin = mid + 1;
		else if (a[mid] > x)
			end = mid - 1;
		else
			return mid;
	}
	return -1;
}

// 计算阶乘递归
//时间复杂度递归时的算法：递归次数*每次递归函数的次数
//空间复杂度递归时的算法：递归函数需要建立栈帧，栈帧需消耗空间，若栈帧中没有额外开辟空间，则都是常数个变量空间
long long Factorial(size_t N)
{                                            //F(N) = N*1
	return N < 2 ? N : Factorial(N - 1)*N;   //这里时间空间复杂度都为O(N)
}



// 计算斐波那契递归Fibonacci的时间复杂度
long long Fibonacci(size_t N)                                 //F(N) = 1+2+4+...2^(N-1)  等比数列，即2^N-1
{                                                             //时间空间复杂度都为O(2^N)
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}


long long* Fibonacci(size_t n)
{
	long long * fibArray = (long long *)malloc((n + 1) * sizeof(long long));
	if (NULL == fibArray)
	{
		exit(1);
	}
	fibArray[0] = 0;
	if (n == 0)
	{
		return fibArray;
	}
	fibArray[1] = 1;                           //时间复杂度：O(N)
	for (int i = 2; i <= n; ++i)               //动态开辟了N个空间，空间复杂度为 O(N)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}