#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <Windows.h>
#include <assert.h>
#include <stdlib.h>

//��ӡ����
void ShowArray(int *a, int n);

//ð������
void BubbleSort(int *a, int n);

//����
void QuickSort(int *a, int left, int right);

#endif