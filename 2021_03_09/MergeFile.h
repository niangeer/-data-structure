#ifndef _MERGEFILE_H_
#define _MERGEFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>

#pragma warning(disable:4996)

//��������
void QuickSort(int *a, int left, int right);

//�鲢�����ļ�
void MergeFile(const char* file);

#endif