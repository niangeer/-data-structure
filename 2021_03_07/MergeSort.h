#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>

//打印数组
void ShowArray(int *a, int n);

//归并排序递归版本
void MergeSort(int *a, int n);

//归并排序非递归版本
void MergeSortNonR(int *a, int n);

#endif