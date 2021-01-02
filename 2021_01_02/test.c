#include <stdio.h>
#include <Windows.h>


//   �㷨Ч�ʷ�������1��ʱ�临�Ӷȣ�������ʱ�䣬�����ŵ����д���
//                 ��2���ռ临�Ӷȣ�������ռ䣬�����Ŷ���ı�������

//��O�Ľ�����ʾ������1���ó���1ȡ������ʱ���е����мӷ�����
//                 ��2�����޸ĺ�����д��������У�ֻ������߽���
//                 ��3�������߽�������Ҳ���1����ȥ���������Ŀ��˵ĳ������õ��Ľ�����Ǵ�O��

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
	printf("%d\n", count);                //ʱ�临�Ӷȣ�O(N*N)
}                                         //�ռ临�Ӷȣ�O(1)


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
	}                                    //ʱ�临�Ӷȣ�O(N)
	printf("%d\n", count);               //�ռ临�Ӷȣ�0(1)
}

void BubbleSort(int* a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)           //������N��
	{                                    //����F(N) = 1+2+3...+n-1  �Ȳ����У���(n*(n-1))/2
		int flag = 0;                    //ʱ�临�Ӷȣ�O(N*N)
		for (int j = 0; j < n - 1 - i; j++)//�ռ临�Ӷȣ�0(1)
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
	int end = n;                                  //ʱ�临�Ӷ�
	while (begin <= end)                           //��������O(1)
	{                                              //������O(log N)
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

// ����׳˵ݹ�
//ʱ�临�Ӷȵݹ�ʱ���㷨���ݹ����*ÿ�εݹ麯���Ĵ���
//�ռ临�Ӷȵݹ�ʱ���㷨���ݹ麯����Ҫ����ջ֡��ջ֡�����Ŀռ䣬��ջ֡��û�ж��⿪�ٿռ䣬���ǳ����������ռ�
long long Factorial(size_t N)
{                                            //F(N) = N*1
	return N < 2 ? N : Factorial(N - 1)*N;   //����ʱ��ռ临�Ӷȶ�ΪO(N)
}



// ����쳲������ݹ�Fibonacci��ʱ�临�Ӷ�
long long Fibonacci(size_t N)                                 //F(N) = 1+2+4+...2^(N-1)  �ȱ����У���2^N-1
{                                                             //ʱ��ռ临�Ӷȶ�ΪO(2^N)
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
	fibArray[1] = 1;                           //ʱ�临�Ӷȣ�O(N)
	for (int i = 2; i <= n; ++i)               //��̬������N���ռ䣬�ռ临�Ӷ�Ϊ O(N)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}