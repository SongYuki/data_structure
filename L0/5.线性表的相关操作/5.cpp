#include<stdio.h>
#include<stdlib.h>
#include"4-0.h"

int main(int argc,char *argv[])
{
	List* list = List_Create();
	int i = 0;
	int j = 1;
	int k = 2;
	
	List_Insert(list,&i,0);
	List_Insert(list,&j,1);
	List_Insert(list,&k,2);
	
	List_Clear(list);
	
	List_Destroy(list);
	
	return 0;
}

List* List_Create()
{
	return NULL;
}

void List_Destroy(List* list)
{
	
}

void List_Clear(List* list)
{
	
}

int List_Length(List* list)
{
	return 0;
}

int List_Insert(List* list,ListNode* node,int pos)
{
	return 0;
}

ListNode* List_Get(List* list,int pos)
{
	return NULL;
}

ListNode* List_Delete(List* list,int pos)
{
	return NULL;
}
