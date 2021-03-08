#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <assert.h>

//打印数组
void ShowArray(int* a, int n);

//普通插入排序
void InsertSort(int* a, int n);

//希尔排序
void ShellSort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//堆排序
void HeapSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);

//快速排序递归版本
void QuickSort(int* a, int left, int right);

//快速排序非递归版本
void QuickSortNonR(int* a, int left, int right);

//归并排序递归版本
void MergeSort(int* a, int n);

//归并排序非递归版本
void MergeSortNonR(int* a, int n);

#endif 