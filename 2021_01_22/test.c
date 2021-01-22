#include <stdio.h>

//���ڷǸ����� X ���ԣ�X ��������ʽ��ÿλ���ְ������ҵ�˳���γɵ����顣
//���磬��� X = 1231����ô��������ʽΪ [1,2,3,1]��
//�����Ǹ����� X ��������ʽ A���������� X + K ��������ʽ��
//
//ʾ��1��
//���룺A = [1, 2, 0, 0], K = 34
//�����[1, 2, 3, 4]
//���ͣ�1200 + 34 = 1234
//
//ʾ��2��
//���룺A = [2, 7, 4], K = 181
//�����[4, 5, 5]


//���ͣ�274 + 181 = 455

int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	//�����K�ĳ���
	int KSize = 0, KCopy = K;
	while (KCopy)
	{
		KCopy /= 10;
		KSize++;
	}
	//ȡ���Ƚϳ��ĸ���len
	int len = ASize > KSize ? ASize : KSize;
	//����һ��len+1�����������������֮�����
	int *dst = (int *)malloc(sizeof(int)*(len + 1));
	//len ���±�
	int i = 0;
	//A ���±�
	int cur = ASize - 1;
	//��λ
	int nextnum = 0;
	//ѭ��len��
	while (len--)
	{
		int a = 0;
		if (cur >= 0)
		{
			a = A[cur];
		}
		//������
		dst[i] = a + (K % 10) + nextnum;
		//�ж��Ƿ��λ
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
	//������������ȣ�ѭ���������λ����Ϊ1
	if (1 == nextnum)
	{
		dst[i] = 1;
		i++;
	}
	//��������
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