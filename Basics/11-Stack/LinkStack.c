#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"LinkStack.h"

int main(int argc, char * argv[])
{
	LinkStack* stack = LinkStack_Create();
	int a[10];
	int i = 0;

	for ( i = 0; i < 10; i++)
	{
		a[i] = i;

		LinkStack_Push(stack, a + i);
	}

	printf("Top:%d\n", *(int*)LinkStack_Top(stack));
	printf("Length:%d\n", LinkStack_Size(stack));

	while (LinkStack_Size(stack)>0)
	{
		printf("Pop:%d\n", *(int*)LinkStack_Pop(stack));
	}
	LinkStack_Destroy(stack);
	return 0;
}

typedef struct _tag_LinkStackNode
{
	LinkStackNode* next;
	void* item;
}TLinkStackNode;

typedef struct _tag_LinkStack
{
	LinkStackNode header;
	int length;
}TLinkStack;

LinkStack* LinkStack_Create()
{
	TLinkStack* ret = (TLinkStack*)malloc(sizeof(TLinkStack));

	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}
	return ret;
}

void LinkStack_Destroy(LinkStack* stack)
{
	LinkStack_Clear(stack);
	free(stack);
}

void LinkStack_Clear(LinkStack* stack)
{
	TLinkStack* sStack = (TLinkStack*)stack;

	if (sStack!=NULL)
	{
		LinkStack_Pop(stack);
	}
}

int LinkStack_Push(LinkStack* stack, void* item)
{
	TLinkStack* sStack = (TLinkStack*)stack;
	TLinkStackNode* node = (TLinkStackNode*)malloc(sizeof(TLinkStackNode));
	int ret = (sStack != NULL) && (item != NULL)&&(node!=NULL);

	if (ret)
	{
	//	node->item = item;
		LinkStackNode* current = (LinkStackNode*)sStack;
		if (current->next!=NULL)
		{
			current = current->next;
		}

	//	item->next = current->next;
		node->next = current->next;
		current->next = item;

		sStack->length++;
	}
	if (!ret)
	{
		free(node);
	}
	return ret;
}

void* LinkStack_Pop(LinkStack* stack)
{
	TLinkStack* sStack = (TLinkStack*)stack;
	LinkStackNode* node = NULL;
	if (sStack!=NULL)
	{
	//	node->item = item;
		LinkStackNode* current = (LinkStackNode*)sStack;

		if (LinkStack_Size(sStack)==0)
		{
			current = current->next;
		}

		node = current->next;
		current->next = node->next;

		sStack->length--;
	}
	void* ret = NULL;

	if (node!=NULL)
	{
		ret = node->item;
		free(node);
	}
	return ret;
}

void* LinkStack_Top(LinkStack* stack)
{
	TLinkStack* sStack = (TLinkStack*)stack;
	TLinkStackNode* ret = NULL;

	if (sStack != NULL)
	{
		LinkStackNode* current = (LinkStackNode*)sStack;

		if (LinkStack_Size(sStack) == 0)
		{
			current = current->next;
		}

		ret = current->next;
	}
	return ret;
}

int LinkStack_Size(LinkStack* stack)
{
	TLinkStack* sStack = (TLinkStack*)stack;
	int ret = -1;

	if (sStack != NULL)
	{
		ret = sStack->length;
	}
	return ret;
}
