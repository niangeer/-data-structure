#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

#include <stdio.h>
#include <assert.h>
#include <Windows.h>

//打印数组
void ShowArray(int *a, int n);

//快速排序
void QuickSort(int *a, int left, int right);

#endif