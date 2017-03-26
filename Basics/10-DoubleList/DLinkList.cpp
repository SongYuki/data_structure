#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"DLinkList.h"


typedef struct _tag_DLinkList
{
	DLinkListNode header;
	DLinkListNode* slider;
	int length;
}TDLinkList;

//O(1)
DLinkList* DLinkList_Create()
{
	TDLinkList* ret = (TDLinkList*)malloc(sizeof(TDLinkList);

	if (ret != NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->header.pre = NULL;
		ret->slider = NULL;
	}
	return ret;
}

//O(1)
void DLinkList_Destroy(DLinkList* list)
{
	free(list);
}

//O(1)
void DLinkList_Clear(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;

	if (sList != NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->header.pre = NULL;
		sList->slider = NULL;
	}
}

//O(1)
int DLinkList_Length(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = -1;

	if (sList != NULL)
	{
		ret = sList->length;
	}
	return ret;
}

//O(n)
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	int ret = (sList != NULL) && (pos >= 0) && (node != NULL);
	int i = 0;

	if (ret)
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;

		for (i = 0; (i < pos) && (current->next != NULL); i++)
		{
			current = current->next;
		}

		next = current->next;

		current->next = node;
		node->next = next;

		if (next != NULL)
		{
			next->pre = node;
		}

		node->pre = current;

		if (sList->length == 0)
		{
			sList->slider = node;
		}

		if (current == (DLinkListNode*)sList)
		{
			node->pre = NULL;
		}
		sList->length++;
	}
	return ret;
}

//O(n)
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;

		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
	}
	return ret;
}

//O(n)
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if ((sList != NULL) && (0 <= pos) && (pos < sList->length))
	{
		DLinkListNode* current = (DLinkListNode*)sList;
		DLinkListNode* next = NULL;

		for (i = 0; i < pos; i++)
		{
			current = current->next;
		}

		ret = current->next;
		next = ret->next;

		current->next = next;

		if (next != NULL)
		{
			next->pre = current;

			if (current == (DLinkListNode*)sList)
			{
				next->pre = NULL;
			}
		}

		if (sList->slider == ret)
		{
			sList->slider = next;
		}

		sList->length--;
	}
	return ret;
}

DLinkListNode* DLinkList_DeleteNode(DLinkList* list, DlinkListNode* node)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;
	int i = 0;

	if (sList != NULL)
	{
		DLinkListNode* current = (DLinkListNode*)sList;

		for (i = 0; i < sList->length; i++)
		{
			if (current->next == node)
			{
				ret = current->next;
				break;
			}

			current = current->next;
		}
		if (ret != NULL)
		{
			DLinkList_Delete(sList, i);
		}
	}
	return ret;
}

DLinkListNode* DLinkList_reset(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Current(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if (sList != NULL)
	{
		ret = sList->slider;
	}
	return ret;
}

DLinkListNode* DLinkList_Next(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if ((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	return ret;
}

DLinkListNode* DlinkList_Pre(DLinkList* list)
{
	TDLinkList* sList = (TDLinkList*)list;
	DLinkListNode* ret = NULL;

	if ((sList != NULL) && (sList->slider != NULL))
	{
		ret = sList->slider;
		sList->slider = ret->pre;
	}
	return ret;
}

struct Value
{
	DLinkListNode header;
	int v;
};

int main(int argc, char *argv[])
{
	DLinkList* list = DLinkList_Create();

	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;

	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;

	DLinkList_Insert(list, (DLinkListNode*)&v1, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v2, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v3, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v4, 0);
	DLinkList_Insert(list, (DLinkListNode*)&v5, 0);

	DLinkList_Reset(list);

	DLinkList_Pre(list);

	printf("%x\n", DLinkList_Current(list));

	DLinkList_Destroy(list);

	return 0;
}

