#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include"CircleList.h"

struct Value
{
	CircleListNode header;
	int v;
};

int main(int argc,char *argv[])
{
	int i = 0;
	CircleList* list = CircleList_Create();
	
	struct Value v1;
	struct Value v2;
	struct Value v3;
	struct Value v4;
	struct Value v5;
	struct Value v6;
	struct Value v7;
	struct Value v8;
	
	v1.v = 1;
	v2.v = 2;
	v3.v = 3;
	v4.v = 4;
	v5.v = 5;
	v6.v = 6;
	v7.v = 7;
	v8.v = 8;
	
	CircleList_Insert(list,(CircleListNode*)&v1,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v2,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v3,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v4,CircleList_Length(list));
	
	CircleList_Insert(list,(CircleListNode*)&v5,5);
	CircleList_Delete(list,0);
	
	for(i=0;i<2*CircleList_Length(list);i++)
	{
		struct Value* pv = (struct Value*)CircleList_Get(list,i);
		printf("%d\n",pv->v);
	}
	
	printf("\n");
	
	while(CircleList_Length(list)>0)
	{
		struct Value* pv = (struct Value*)CircleList_Delete(list,0);
		printf("%d\n",pv->v);
	}
	printf("\n");
	
	CircleList_Insert(list,(CircleListNode*)&v1,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v2,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v3,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v4,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v5,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v6,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v7,CircleList_Length(list));
	CircleList_Insert(list,(CircleListNode*)&v8,CircleList_Length(list));

	for(i=0;i<CircleList_Length(list);i++)
	{
		struct Value* pv = (struct Value*)CircleList_Next(list);
		printf("%d\n",pv->v);
	}
	
	printf("\n");
	
	CircleList_Reset(list);
	
	while(CircleList_Length(list)>0)
	{
		struct Value* pv = NULL;
		for(i=1;i<3;i++)
		{
			CircleList_Next(list);
		}
		
		pv = (struct Value*)CircleList_Current(list);
		printf("%d\n",pv->v);
		
		CircleList_DeleteNode(list,(CircleListNode*)pv);
	}
	
	CircleList_Destroy(list);
	
	return 0;

}

typedef struct _tag_CircleList
{
	CircleListNode header;
	CircleListNode* slider;
	int length;
}TCircleList;

//O(1)
CircleList* CircleList_Create()
{
	TCircleList* ret = (TCircleList*)malloc(sizeof(TCircleList));
	
	if(ret!=NULL)
	{
		ret->length = 0;
		ret->header.next = NULL;
		ret->slider = NULL;
	}
	return ret;
}

//O(1)
void CircleList_Destroy(CircleList* list)
{
	free(list);
}

//O(1)
void CircleList_Clear(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	
	if(sList!=NULL)
	{
		sList->length = 0;
		sList->header.next = NULL;
		sList->slider = NULL;
	}
}

//O(1)
int CircleList_Length(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = -1;
	
	if(sList!=NULL)
	{
		ret = sList->length;
	}
	return ret;
}

//O(n)
int CircleList_Insert(CircleList* list,CircleListNode* node,int pos)
{
	TCircleList* sList = (TCircleList*)list;
	int ret = (sList!=NULL)&&(pos>=0)&&(node!=NULL);
	int i = 0;
	
	if(ret)
	{
		CircleListNode* current  = (CircleListNode*)sList;
		
		for(i=0;(i<pos)&&(current->next!=NULL);i++)
		{
			current = current->next;
		}
		
		node->next = current->next;
		current->next = node;
		
		if(sList->length==0)
		{
			sList->slider = node;
		}
		
		sList->length++;

		if (current == (CircleListNode*)sList)
		{
			CircleListNode* last = CircleList_Get(sList, sList->length - 1);
			last->next = current->next;
		}
	}
	return ret;
}

//O(n)
CircleListNode* CircleList_Get(CircleList* list,int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;
	
	if((sList!=NULL)&&(pos>=0)&&(sList->length>0))
	{
		CircleListNode* current = (CircleListNode*)sList;
		
		for(i=0;i<pos;i++)
		{
			current = current->next;
		}
		
		ret = current->next;
	}
	
	return ret;
}

//O(n)
CircleListNode* CircleList_Delete(CircleList* list,int pos)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;
	
	if((sList!=NULL)&&(pos>=0)&&(sList->length>0))
	{
		CircleListNode* current = (CircleListNode*)sList;
		CircleListNode* last = NULL;
		
		for(i=0;i<pos;i++)
		{
			current = current->next;
		}

		if (current == (CircleListNode*)sList)
		{
			last = (CircleListNode*)CircleList_Get(sList, sList->length - 1);
		}
		
		ret = current->next;
		current->next = ret->next;
		
		sList->length--;
		
		if(last!=NULL)
		{
			sList->header.next = ret->next;
			last->next = ret->next;
		}
		
		if(sList->slider == ret)
		{
			sList->slider = ret->next;
		}
		
		if(sList->length==0)
		{
			sList->header.next = NULL;
			sList->slider = NULL;
		}
	}
	return ret;
}

//O(n)
CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	int i = 0;
	
	if(sList!=NULL)
	{
		CircleListNode* current = (CircleListNode*)sList;
		
		for(i=0;i<sList->length;i++)
		{
			if(current->next==node)
			{
				ret = current->next;
				break;
			}
			
			current = current->next; 
		}
		if(ret!=NULL)
		{
			CircleList_Delete(sList,i);
		}
	}
	return ret;
}

//O(1)
CircleListNode* CircleList_Reset(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	
	if(sList!=NULL)
	{
		sList->slider = sList->header.next;
		ret = sList->slider;
	}
	return ret;
}

//O(1)
CircleListNode* CircleList_Current(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	
	if(sList!=NULL)
	{
		ret = sList->slider;
	}
	return ret;
}

//O(1)
CircleListNode* CircleList_Next(CircleList* list)
{
	TCircleList* sList = (TCircleList*)list;
	CircleListNode* ret = NULL;
	
	if((sList!=NULL)&&(sList->slider!=NULL))
	{
		ret = sList->slider;
		sList->slider = ret->next;
	}
	return ret;
}
