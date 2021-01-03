#include "SeqList.h"

void SeqListInit(SeqList* ps)           // 顺序表初始化
{
	assert(ps);
	ps->a = (SLDataType*)malloc(sizeof(SLDataType*)*CAP);
	if (NULL == ps->a)
	{
		printf("malloc error!\n");
		exit(1);
	}
	ps->size = 0;
	ps->capacity = CAP;
}

void SeqListShow(SeqList* ps)      //顺序表展示
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* ps)    //释放内存
{
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

static void CheckCapacity(SeqList* ps)      //检查顺序表是否已满，满则增容
{
	if (ps->size == ps->capacity)
	{
		SLDataType* p = (SLDataType*)realloc(ps->a, sizeof(SLDataType)*(ps->capacity + INC_CAP));
		if (NULL == p)
		{
			printf("relloc error!\n");
			exit(1);
		}
		ps->a = p;
		ps->capacity += INC_CAP;
		printf("realloc success!\n");
	}
}

void SeqListPushBack(SeqList* ps, SLDataType x)    //顺序表尾插
{
	assert(ps);
	CheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size += 1;
}

void SeqListPopBack(SeqList* ps)           //顺序表尾删
{
	assert(ps);
	ps->size--;
}

void SeqListPushFront(SeqList* ps, SLDataType x)    //顺序表头插    
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

void SeqListPopFront(SeqList* ps)      //顺序表头删
{
	assert(ps);
	for (int i = 0; i < ps->size-1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size -= 1;
}

void SeqListInsert(SeqList* ps, int pos, SLDataType x)    //顺序表在pos位置插入x    
{
	assert(ps);
	assert(pos <= ps->size && pos >= 0);
	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; i--)
	{
	ps->a[i + 1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->size += 1;
}

void SeqListErase(SeqList* ps, int pos)     // 顺序表删除pos位置的值
{
	assert(ps);
	assert(pos < ps->size && 0 <= pos);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size -= 1;
}

int SeqListFind(SeqList* ps, SLDataType x)    // 顺序表查找
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (x == ps->a[i])
		{
			return i;
		}
	}
	return -1;
}