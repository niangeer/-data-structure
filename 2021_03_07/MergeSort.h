#ifndef _MERGESORT_H_
#define _MERGESORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>

//��ӡ����
void ShowArray(int *a, int n);

//�鲢����ݹ�汾
void MergeSort(int *a, int n);

//�鲢����ǵݹ�汾
void MergeSortNonR(int *a, int n);

#endif