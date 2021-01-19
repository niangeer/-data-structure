#include "SeqList.h"

//顺序表初始化
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

//顺序表展示
void SeqListShow(SeqList* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

//顺序表释放内存
void SeqListDestory(SeqList* ps)
{
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//检查顺序表是否已满，满则增容
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

//顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size += 1;
	printf("插入成功!\n");
}

//顺序表尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	if (0 == ps->size)
		printf("已全部清空!\n");
	else
	{
		ps->size -= 1;
		printf("删除成功!\n");
	}
}

//顺序表头插
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

//顺序表头删
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
		printf("删除成功!\n");
	}
	else
		printf("已全部清空!\n");
}

//顺序表查找
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
	printf("要查找的目标不存在!\n");
	return -1;
}

//顺序表pos位置上插入x
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

//顺序表pos位置上删除
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
		printf("删除成功!\n");
	}
	else
		printf("已全部清空!\n");
}