#include <stdio.h>
#include <windows.h>

//1，给你一个数组 nums 和一个值 val ,你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//   要求：不要使用额外的数组空间，你必须仅使用 O(1) 额外空间 并 原地 修改输入数组。
//         元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素
//示例1:
//给定 nums = [3 ,2 ,2 ,3 ],val = 3;
//函数应该返回新的长度 2，并且 nums 中的前两个元素均为 2；
//你不需要考虑数组中超出新长度后面的元素。
//示例2：
//给定nums=[0 ,1 ,2 ,2 ,3 ,0 ,4 ,2 ],val = 2;
//函数应该返回新的长度 5，并且 nums 中前五个元素为 0, 1, 3, 0, 4；
//注意这五个元素可为任意顺序
//你不需要考虑数组中超出新长度后面的元素。
//原题链接：https://leetcode-cn.com/problems/remove-element/

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



//2，给定一个排序数组，你需要在 原地 删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
//   不要使用额外的数组空间，你必须在 原地 修改输入数组并在使用 O(1) 额外空间的条件下完成。 
//   示例1：
//   给定数组 nums = [1 , 1, 2];
//   函数应该返回新的长度 2，并且原数组 nums 的前两个元素被修改为 1, 2。
//   你不需要考虑数组中超出新长度后面的元素。
//   示例2：
//   给定 nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
//   函数应该返回新的长度 5，并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
//   你不需要考虑数组中超出新长度后面的元素。
//   原题链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/

int removeDuplicates(int* nums, int numsSize){
	if (0 == numsSize)           //空数组的情况
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


