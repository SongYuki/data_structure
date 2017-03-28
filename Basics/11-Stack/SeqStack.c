#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "SeqStack.h"

int main(int argc, char *argv[])
{
	SeqStack* stack = SeqStack_Create(20);
	int a[10];
	int i = 0;

	for ( i = 0; i < 10; i++)
	{
		a[i] = i;
		SeqStack_Push(stack, a + i);
	}

	printf("Top:%d\n", *(int*)SeqStack_Top(stack));
	printf("Capacity:%d\n", SeqStack_Capacity(stack));
	printf("Length:%d\n", SeqStack_Size(stack));

	while (SeqStack_Size(stack)>0)
	{
		printf("Pop:%d\n", *(int*)SeqStack_Pop(stack));
	}
	SeqStack_Destroy(stack);
	return 0;
}

typedef struct _tag_SeqStack
{
	int capacity;
	int size;
	void* item;
}TSeqStack;

SeqStack* SeqStack_Create(int capacity)
{
	TSeqStack* ret = NULL;

	if (capacity >= 0)
	{
		ret = (TSeqStack*)malloc(sizeof(TSeqStack) + sizeof(void)*capacity);
	}

	if (ret != NULL)
	{
		ret->capacity = capacity;
		ret->size = 0;
		ret->item = (void*)(ret + 1);
	}
	return ret;
}

void SeqStack_Destroy(SeqStack* stack)
{
	free(stack);
}

void SeqStack_Clear(SeqStack* stack)
{
	TSeqStack* sStack = (TSeqStack*)stack;

	if (sStack!=NULL)
	{
		sStack->size = 0;
	}
}

int SeqStack_Size(SeqStack* stack)
{
	TSeqStack* sStack = (TSeqStack*)stack;
	int ret = -1;

	if (sStack!=NULL)
	{
		ret = sStack->size;
	}
	return ret;
}

int SeqStack_Push(SeqStack* stack, void* Item)
{
	TSeqStack* sStack = (TSeqStack*)stack;
	int ret = (sStack != NULL);
	
	ret = ret && (sStack->size + 1 <= sStack->capacity);

	if (ret)
	{
		int pos = sStack->size-1;

		sStack->item[pos] = (void*)Item;

		sStack->size++;
	}
	return ret;
}


void* SeqStack_Pop(SeqStack* stack)
{
	TSeqStack* sStack = (TSeqStack*)stack;
	(void*)ret = SeqStack_Top(sStack);

	if (ret!=NULL)
	{
		sStack->size--;
	}
	return ret;
}

void* SeqStack_Top(SeqStack* stack)
{
	TSeqStack* sStack = (TSeqStack*)stack;
	(void*)ret = NULL;

	if (sStack != NULL)
	{
		int pos = SeqStack_Size(sStack) - 1;
		ret = (void*)(sStack->item[pos]);
	}
	return ret;
}

int SeqStack_Capacity(SeqStack* stack)
{
	TSeqStack* sStack = (TSeqStack*)stack;
	int ret = -1;

	if (sStack£¡=NULL)
	{
		ret = sStack->capacity;
	}
	return ret;
}
