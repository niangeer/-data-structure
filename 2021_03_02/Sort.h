#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

// 直接插入排序
void InsertSort(int *a, int n);

// 希尔排序
void ShellSort(int* a, int n);

//打印数据
void PrintArr(int* a, int n);

// 测试排序的性能对比
void TestOP();

#endif