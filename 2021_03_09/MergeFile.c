#include "MergeFile.h"

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//三数取中法
int GetMidIndex(int* a, int left, int right)
{
	int mid = ((right - left) >> 1) + left;

	if (a[mid] > a[left])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
	else  //a[mid]<=a[left]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

//快速排序子函数（左右指针法单趟排序）
int PartSort(int* a, int left, int right)
{
	//三数取中
	int midIndex = GetMidIndex(a, left, right);
	//将三数的中数与最后一个数交换
	Swap(&a[midIndex], &a[right]);

	//以右边为基准
	int keyIndex = right;

	while (left < right)
	{
		//left找大
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		//right找小
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[right], &a[keyIndex]);

	return right;
}

//快速排序
void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;

	int div = PartSort(a, left, right);

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}


//归并文件子函数（把要归并的文件进行排序）
void _MergeFile(char* file0, char* file1, char* mfile)
{
	//打开三个文件
	FILE* fout1 = fopen(file0, "r");
	if (NULL == fout1)
	{
		printf("open error\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file1, "r");
	if (NULL == fout2)
	{
		printf("open error\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (NULL == fin)
	{
		printf("open error\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d", &num1);
	int ret2 = fscanf(fout2, "%d", &num2);

	//当其中一个文件读取完时结束循环
	while (ret1 != EOF && ret2 != EOF)
	{
		//将两文件中小的值写入mfile
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d", &num2);
		}
	}

	//将两文件中未读取完的数据输入到mfile
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d", &num2);
	}

	//关闭文件
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

//归并排序文件
void MergeFile(const char* file)
{
	//打开文件
	FILE* fout = fopen(file, "r");
	if (NULL == fout)
	{
		printf("open error\n");
		system("pause");
		exit(-1);
	}
	//将文件分割成一段一段数据，内存排序后写到小文件（这里假设100个数据，一份十个数据）
	int a[10];
	int index = 0;
	int n = 10;
	int getData = 0;  //getData获取源文件中的数据
	int filei = 0;    //给十个小文件标号
	char subfile[32];  //小文件的名字

	while ((fscanf(fout, "%d", &getData)) != EOF)
	{
		//将源文件数据放入内存中
		a[index++] = getData;

		if (n == index)
		{
			//在内存中将数据进行排序
			QuickSort(a, 0, n - 1);

			//给小文件标号
			sprintf(subfile, "%d", filei++);
			//打开小文件
			FILE* fin = fopen(subfile, "w");
			if (NULL == fin)
			{
				printf("open error\n");
				exit(-1);
			}
			//将内存中的数据写入小文件
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}

			index = 0;
			fclose(fin);
		}
	}

	//将十个小文件进行归并，实现整体有序
	char file0[32] = "0";
	char file1[32] = "1";
	char mfile[32] = "01";
	for (int i = 1; i < n; i++)
	{
		_MergeFile(file0, file1, mfile);

		strcpy(file0, mfile);
		sprintf(file1, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	fclose(fout);
}
