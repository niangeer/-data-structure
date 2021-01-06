#include <stdio.h>
#include <windows.h>

//1������һ������ nums ��һ��ֵ val ,����Ҫ ԭ�� �Ƴ�������ֵ���� val ��Ԫ�أ��������Ƴ���������³��ȡ�
//   Ҫ�󣺲�Ҫʹ�ö��������ռ䣬������ʹ�� O(1) ����ռ� �� ԭ�� �޸��������顣
//         Ԫ�ص�˳����Ըı䡣�㲻��Ҫ���������г����³��Ⱥ����Ԫ��
//ʾ��1:
//���� nums = [3 ,2 ,2 ,3 ],val = 3;
//����Ӧ�÷����µĳ��� 2������ nums �е�ǰ����Ԫ�ؾ�Ϊ 2��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ʾ��2��
//����nums=[0 ,1 ,2 ,2 ,3 ,0 ,4 ,2 ],val = 2;
//����Ӧ�÷����µĳ��� 5������ nums ��ǰ���Ԫ��Ϊ 0, 1, 3, 0, 4��
//ע�������Ԫ�ؿ�Ϊ����˳��
//�㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//ԭ�����ӣ�https://leetcode-cn.com/problems/remove-element/

int removeElement(int* nums, int numsSize, int val){
	int dst = 0;
	int src = 0;
	while (src < numsSize)
	{
		if (val == nums[src])
		{
			src++;
		}
		else
		{
			nums[dst] = nums[src];
			dst++; 
			src++;
		}
	}
	return dst;
}



//2������һ���������飬����Ҫ�� ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹ��ÿ��Ԫ��ֻ����һ�Σ������Ƴ���������³��ȡ�
//   ��Ҫʹ�ö��������ռ䣬������� ԭ�� �޸��������鲢��ʹ�� O(1) ����ռ����������ɡ� 
//   ʾ��1��
//   �������� nums = [1 , 1, 2];
//   ����Ӧ�÷����µĳ��� 2������ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2��
//   �㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//   ʾ��2��
//   ���� nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
//   ����Ӧ�÷����µĳ��� 5������ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4��
//   �㲻��Ҫ���������г����³��Ⱥ����Ԫ�ء�
//   ԭ�����ӣ�https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/

int removeDuplicates(int* nums, int numsSize){
	if (0 == numsSize)           //����������
	{
		return 0;
	}
	int cur = 1;
	int prev = 0;
	int dst = 0;
	while (cur < numsSize)
	{
		if (nums[prev] != nums[cur])
		{
			nums[dst] = nums[prev];
			dst++; prev++; cur++;
		}
		else
		{
			cur++; prev++;
		}
	}
	nums[dst] = nums[prev];
	dst++;
	return dst;
}


