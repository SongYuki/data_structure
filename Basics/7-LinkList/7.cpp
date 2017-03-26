#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"7.h"

typedef struct _tag_LinkList
{
	LinkListNode header;
	int length;
}TLinkList;

struct Value
{
	LinkListNode header;
	int v;
};

int main(int argc,char *argv[])
{
	int i = 0;
	LinkList* list = LinkList_Create();
	
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
	
	LinkList_Insert(list,(LinkListNode*)&v1,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v2,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v3,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v4,LinkList_Length(list));
	LinkList_Insert(list,(LinkListNode*)&v5,LinkList_Length(list));
	
	for(i=0;i<LinkList_Length(list);i++)
	{
		struct Value* pv = (struct Value*)LinkList_Get(list,i);
		printf("%d\n",pv->v);
	}
	
	while(LinkList_Length(list)>0)
	{
		struct Value* pv = (struct Value*)LinkList_Delete(list,0);
		printf("%d\n",pv->v);
	}
	
	LinkList_Destroy(list);
	
	return 0;
}

//O(1)
LinkList* LinkList_Create()
{
	TLinkList* ret = (TLinkList*)malloc(sizeof(TLinkList));
	
	if(ret!=NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
	}
	
	return ret;
}

//O(1)
void LinkList_Destroy(LinkList* list)
{
	free(list);
}

//O(1)
void LinkList_Clear(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;
	
	if(sList!=NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
	 } 
}

//O(1)
int LinkList_Length(LinkList* list)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = -1;
	
	if(sList!=NULL)
	{
		ret = sList->length;
	}
	return ret;
}

//O(n)
int LinkList_Insert(LinkList* list,LinkListNode* node,int pos)
{
	TLinkList* sList = (TLinkList*)list;
	int ret = (sList!=NULL)&&(pos>=0)&&(node!=NULL);
	int i = 0;
	
	if(ret)
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0;(i<pos)&&(current->next!=NULL);i++)
		{
			current = current->next;
		}
		
		node->next = current->next;
		current->next = node;
		
		sList->length++;
	}
	return ret;
}

//O(n)
LinkListNode* LinkList_Get(LinkList* list,int pos)
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret = NULL;
	int i = 0;
	
	if((sList!=NULL)&&(0<=pos)&&(pos<sList->length))
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0;i<pos;i++)
		{
			current = current->next;
		}
		
		ret = current->next;
	}
	
	return ret;
}

//O(n)
LinkListNode* LinkList_Delete(LinkList* list,int pos)
{
	TLinkList* sList = (TLinkList*)list;
	LinkListNode* ret = NULL;
	int i = 0;
	
	if((sList!=NULL)&&(0<=pos)&&(pos<sList->length))
	{
		LinkListNode* current = (LinkListNode*)sList;
		
		for(i=0;i<pos;i++)
		{
			current = current->next;
		 } 
		 
		 ret = current->next;
		 current->next = ret->next;
		 
		 sList->length--;
	 } 
	 
	 return ret;
}
