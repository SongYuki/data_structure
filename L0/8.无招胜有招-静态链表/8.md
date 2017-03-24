单链表的相对劣势
+ 单链表的实现严重依赖指针
+ 数据元素中必须包含一个额外的指针域
+ 没有指针的程序设计语言无法实现

顺序表的改进-静态链表
+ 顺序表数组中的元素由两个数据域组成:data和next
+ data域用于存储数据
+ next域用于存储下一个元素在数组中的下标

静态链表是在顺序表的基础上利用数组实现的单链表

静态链表的结构体定义：

    ```c
    typedef struct _tag_StaticListNode
    {
        unsigned int data;
        int next;
    }TStaticListNode;
    typedef struct _tag_StaticList
    {
        int capacity;
        TStaticListNode header;
        TStaticListNode node[];
    }TStaticList;
    ```
    
获取第pos个元素操作
+ 判断线性表是否合法
+ 判断位置是否合法
+ 由表头开始通过next域移动pos次后，当前元素的next域即要获取元素在数组中的下标

    ```c
    sList->node[0] = sList->header;
    
    for(i=0;i<pos;i++)
    {
        current = sList->node[current].next;
    }
    object = sList->node[current].next;
    ```
    
插入元素到位置pos的算法
+ 判断线性表是否合法
+ 盘算插入位置是否合法
+ 在数组中查找空闲位置Index
+ 由表头开始通过Next域移动pos次后，当前元素的next域为要插入的位置
+ 将新元素插入
+ 线性表长度+1

    ```c
    for(i=0;(i<pos)&&(sList->node[current].next!=0);i++)
    {
        current = sList->node[current].next;
    }
    sList->node[index].next = sList->node[current].next;
    sList->node[current].next = index;
    ```
    
删除第pos个元素的算法
+ 判断线性表是否合法
+ 判断插入位置是否合法
+ 获取第pos个元素
+ 将第pos个元素从链表中删除
+ 线性表长度-1

    ```c
    object = sList->node[current].next;
    sList->node[current].next = sList->node[object].next;
    ```
    
+ 静态链表是单链表的另一种实现方式
+ 静态链表的实现媒介不是指针而是数组
+ 静态链表主要用于不支持指针的程序设计语言中
+ 静态链表的实现是一种内存管理的简易方法

Question:
为什么静态链表结构体中要再定义个```header```成员而不是直接使用```node[0]```？



