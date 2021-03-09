#include "MergeFile.h"

void Swap(int *p1, int *p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//����ȡ�з�
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

//���������Ӻ���������ָ�뷨��������
int PartSort(int* a, int left, int right)
{
	//����ȡ��
	int midIndex = GetMidIndex(a, left, right);
	//�����������������һ��������
	Swap(&a[midIndex], &a[right]);

	//���ұ�Ϊ��׼
	int keyIndex = right;

	while (left < right)
	{
		//left�Ҵ�
		while (left < right && a[left] <= a[keyIndex])
		{
			left++;
		}
		//right��С
		while (left < right && a[right] >= a[keyIndex])
		{
			right--;
		}
		Swap(&a[left], &a[right]);
	}

	Swap(&a[right], &a[keyIndex]);

	return right;
}

//��������
void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;

	int div = PartSort(a, left, right);

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);
}


//�鲢�ļ��Ӻ�������Ҫ�鲢���ļ���������
void _MergeFile(char* file0, char* file1, char* mfile)
{
	//�������ļ�
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

	//������һ���ļ���ȡ��ʱ����ѭ��
	while (ret1 != EOF && ret2 != EOF)
	{
		//�����ļ���С��ֵд��mfile
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

	//�����ļ���δ��ȡ����������뵽mfile
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

	//�ر��ļ�
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

//�鲢�����ļ�
void MergeFile(const char* file)
{
	//���ļ�
	FILE* fout = fopen(file, "r");
	if (NULL == fout)
	{
		printf("open error\n");
		system("pause");
		exit(-1);
	}
	//���ļ��ָ��һ��һ�����ݣ��ڴ������д��С�ļ����������100�����ݣ�һ��ʮ�����ݣ�
	int a[10];
	int index = 0;
	int n = 10;
	int getData = 0;  //getData��ȡԴ�ļ��е�����
	int filei = 0;    //��ʮ��С�ļ����
	char subfile[32];  //С�ļ�������

	while ((fscanf(fout, "%d", &getData)) != EOF)
	{
		//��Դ�ļ����ݷ����ڴ���
		a[index++] = getData;

		if (n == index)
		{
			//���ڴ��н����ݽ�������
			QuickSort(a, 0, n - 1);

			//��С�ļ����
			sprintf(subfile, "%d", filei++);
			//��С�ļ�
			FILE* fin = fopen(subfile, "w");
			if (NULL == fin)
			{
				printf("open error\n");
				exit(-1);
			}
			//���ڴ��е�����д��С�ļ�
			for (int i = 0; i < n; i++)
			{
				fprintf(fin, "%d\n", a[i]);
			}

			index = 0;
			fclose(fin);
		}
	}

	//��ʮ��С�ļ����й鲢��ʵ����������
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
