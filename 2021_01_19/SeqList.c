#include "SeqList.h"

//˳����ʼ��
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDataType*)malloc(sizeof(SLDataType)*CAP);
	if (NULL == ps->a)
	{
		printf("malloc error!\n");
		exit(1);
	}
	memset(ps->a, 0, CAP*(sizeof(SLDataType)));
	ps->size = 0;
	ps->capacity = CAP;
}

//˳���չʾ
void SeqListShow(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//˳����ͷ��ڴ�
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//���˳����Ƿ���������������
void CheckCapacity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		SLDataType* p = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*(ps->capacity + INC_CAP));
		if (NULL == p)
		{
			printf("INC error!\n");
			exit(-1);
		}
		ps->a = p;
		ps->capacity += INC_CAP;
	}
}

//˳���β��
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size += 1;
	printf("����ɹ�!\n");
}

//˳���βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (0 == ps->size)
		printf("��ȫ�����!\n");
	else
	{
		ps->size -= 1;
		printf("ɾ���ɹ�!\n");
	}
}

//˳���ͷ��
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	for (int i = ps->size-1; 0 <= i; i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->size += 1;
}

//˳���ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	if (ps->size)
	{
		ps->size -= 1;
		printf("ɾ���ɹ�!\n");
	}
	else
		printf("��ȫ�����!\n");
}

//˳������
int SeqListFind(SeqList* ps,SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	printf("Ҫ���ҵ�Ŀ�겻����!\n");
	return -1;
}

//˳���posλ���ϲ���x
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
	    ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size += 1;
}

//˳���posλ����ɾ��
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	assert(0 <= pos&&pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	if (ps->size)
	{
		ps->size -= 1;
		printf("ɾ���ɹ�!\n");
	}
	else
		printf("��ȫ�����!\n");
}