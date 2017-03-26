#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"6.h"

typedef unsigned long long TSeqListNode;

typedef struct _tag_SeqList
{
	int capacity;
	int length;
	TSeqListNode* node;
}TSeqList;

int main(int argc,char *argv[])
{
	SeqList* list = SeqList_Create(6);
	
	int i = 0;
	int j = 1;
	int k = 2;
	int x = 3;
	int y = 4;
	int z = 5;
	int index = 0;
	
	SeqList_Insert(list,&i,0);
	SeqList_Insert(list,&j,0);
	SeqList_Insert(list,&k,0);
	SeqList_Insert(list,&x,0);
	SeqList_Insert(list,&y,0);
	SeqList_Insert(list,&z,0);
	
	for(index=0;index<SeqList_Length(list);index++)
	{
		int* p = (int*)SeqList_Get(list,index);
		printf("%d\n",*p);
	}
	printf("\n");
	
	while(SeqList_Length(list)>0)
	{
		int* p = (int*)SeqList_Delete(list,0);
		printf("%d\n",*p);
	}
	SeqList_Destroy(list);
	return 0;
}

SeqList* SeqList_Create(int capacity)//O(1)
{
	TSeqList* ret = NULL;
	if(capacity>=0)
	{
		ret = (TSeqList*)malloc(sizeof(TSeqList)+sizeof(TSeqListNode)*capacity);
	}
	if(ret!=NULL)
	{
		ret->capacity = capacity;
		ret->length = 0;
		ret->node = (TSeqListNode*)(ret+1);
	}
	return ret;
}

void SeqList_Destroy(SeqList* list) //O(1)
{
	free(list);
}

void SeqList_Clear(SeqList* list)//O(1)
{
	TSeqList* sList = (TSeqList*)list;
	if(sList!=NULL)
	{
		sList->length = 0;
	}
}

int SeqList_Length(SeqList* list) //O(1)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	if(sList!=NULL)
	{
		ret = sList->length;
	}
	return ret;
}

int SeqList_Capacity(SeqList* list) //O(1)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = -1;
	
	if(sList!=NULL)
	{
		ret = sList->capacity;
	}
	return ret;
}

int SeqList_Insert(SeqList* list,SeqListNode* node,int pos) //O(n)
{
	TSeqList* sList = (TSeqList*)list;
	int ret = (sList!=NULL);
	int i = 0;
	
	ret = ret&&(sList->length+1<=sList->capacity);
	ret = ret&&(0<=pos);
	
	if(ret)
	{
		if(pos>=sList->length)
		{
			pos = sList->length;
		}
		for(i=sList->length;i>pos;i--)
		{
			sList->node[i] = sList->node[i-1];
		}
		
		sList->node[i] = (TSeqListNode)node;
		sList->length++;
	}
	return ret;
}

SeqListNode* SeqList_Get(SeqList* list,int pos)  //O(1)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = NULL;
	
	if((sList!=NULL)&&(0<=pos)&&(pos<sList->length))
	{
		ret = (SeqListNode*)(sList->node[pos]);
	}
	return ret;
}

SeqListNode* SeqList_Delete(SeqList* list,int pos) //O(n)
{
	TSeqList* sList = (TSeqList*)list;
	SeqListNode* ret = SeqList_Get(list,pos);
	int i = 0;
	
	if(ret!=NULL)
	{
		for(i=pos+1;i<sList->length;i++)
		{
			sList->node[i-1] = sList->node[i];
		}
		sList->length--;
	}
	return ret;
}
