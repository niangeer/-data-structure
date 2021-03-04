#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

//打印数组
void ShowArray(int *a, int n);

//冒泡排序
void BubbleSort(int *a, int n);

//快排
void QuickSort(int *a, int left, int right);

#endif