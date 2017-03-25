单链表可以用于表示任意的线性关系
有些线性关系是循环的，即没有队尾元素

循环链表：将单链表中最后一个数据元素的next指针指向第一个元素

循环链表拥有单链表的所有操作
+ 创建链表
+ 销毁链表
+ 获取链表长度
+ 清空链表
+ 获取第pos个元素操作
+ 插入元素到位置pos
+ 删除位置pos处的元素

在循环链表中可以定义一个“当前”指针，这个指针通常称为游标slider，可以通过这个游标来遍历链表中的所有元素

循环链表的新操作
+ 获取当前游标指向的数据元素
```CircleListNode* CircleList_Current(CircleList* list);```

+ 将游标重置指向链表中的第一个数据元素
```CircleListNode* CircleList_Reset(CircleList* list);```

+ 将游标移动指向到链表中的下一个数据元素
```CircleListNode* CircleList_Next(CircleList* list);```

+ 直接指定删除链表中的某个数据元素
```CircleListNode* CircleList_DeleteNode(CircleList* list,CircleListNode* node);```

约瑟夫问题：
n个人围成一个圆圈，首先第一个人从1开始一个人一个人顺时针报数，报到第m个人，令其出列。然后再从下一个人开始从1顺时针报数，报到第m个人，再令其出列，如此下去，求出列顺序

+ 循环链表只是在单链表的基础上做了一个加强
+ 循环链表可以完全取代单链表的使用
+ 循环链表的Next和Current操作可以高效的遍历链表中的所有元素



