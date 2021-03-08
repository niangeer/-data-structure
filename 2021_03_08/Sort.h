#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <assert.h>

//��ӡ����
void ShowArray(int* a, int n);

//��ͨ��������
void InsertSort(int* a, int n);

//ϣ������
void ShellSort(int* a, int n);

//ѡ������
void SelectSort(int* a, int n);

//������
void HeapSort(int* a, int n);

//ð������
void BubbleSort(int* a, int n);

//��������ݹ�汾
void QuickSort(int* a, int left, int right);

//��������ǵݹ�汾
void QuickSortNonR(int* a, int left, int right);

//�鲢����ݹ�汾
void MergeSort(int* a, int n);

//�鲢����ǵݹ�汾
void MergeSortNonR(int* a, int n);

#endif 