#ifndef _EG_2_1_H_
#define _EG_2_1_H_

typedef void List;
typedef void ListNode;

List* List_Create();

void List_Destroy(List* list);

void List_Clear(List* list);

int List_Length(List* list);

int List_Insert(List* list,ListNode* node,int pos);

ListNode* List_Get(List* list,int pos);

ListNode* List_Delete(List* list,int pos);

#endif 
