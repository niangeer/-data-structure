#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

//打印数组
void ShowArray(int *a, int n);

//选择排序
void SelectSort(int *a, int n);

//堆排序
void HeapSort(int *a, int n);

//测试排序的性能对比
void TestOP();

#endif