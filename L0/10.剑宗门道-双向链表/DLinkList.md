单链表的局限
+ 单链表的结点都只有一个指向下一个结点的指针
+ 单链表的数据元素无法直接访问其前驱元素

逆序访问单链表重的元素是及其耗时的操作

    ```c
    len = LinkList_Length(list);
    for(i=len-1;len>=0;i--)
    {
        LinkListNode* p = LinkList_Get(list,i);
        //访问p中的数据
    }
    ```
    
双向链表的定义：在单链表的结点中增加一个指向其前驱的pre指针

双向链表的插入操作

    ```c
    current->next = node;
    node->next = next;
    next->pre = node;
    node->pre = current;
    ```
    


双向链表的删除操作

    ```c
    current->next = next;
    next->pre = current;
    ```
    
双向链表的新操作
+ 获取当前游标指向的数据元素```DLinkListNode* DLinkList_Current(DLinkList* list);```
+ 将游标重置指向链表中的第一个数据元素```DLinkListNode* DLinkList_Reset(DLinkList* list);```
+ 将游标移动指向到链表中的下一个数据元素```DLinkListNode* DLinkList_Next(DLinkList* list);```
+ 将游标移动指向到链表中的上一个数据元素```DLinkListNode* DLinkList_Pre(DLinkList* list);```
+ 直接指定删除链表中的某个数据元素```DLinkListNode* DLinkList_DeleteNode(DLinkList* list,DLinkListNode* node);```






