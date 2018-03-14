/*
	shorter is better 能递归则一定不用栈，能用STL则一定不自己实现
	不提倡防御式编程。不需要检查malloc()/new返回的指针是否为Nullptr;不需要检查内部函数入口参数的有效性
	
	1.在判断两个浮点数a和b是否相等时，不要用a==b，应该判断二者之差的绝对值fabs(a-b)是否小于某个阈值，例如1e-9
	
	2.判断一个证书是否为奇数，用x%2!=0,不要用x%2==1,因为x可能是负数。
	
	3.用char的值作为数组下标（例如，统计字符串中每个字符出现的次数），要考虑到char可能是负数。先强制转型为unsigned char，再用作下标。这涉及到C++整型提升的规则。
	
	Effective STL
	1.vector和string优先于动态分配的数组
	首先，在性能上，由于vector能够保证连续内存，因此一旦分配了后，它的性能跟原始数组相当。
	其次，如果用new，意味着你要确保后面进行了delete，一旦忘记了，就会出现bug，且这样需要都写一行delete，代码不够短。
	再次，声明多维数组的话，只能一个一个new，int** ary = new int*[row_num];for(int i=0;i<row_num;++i){ary[i]=new int[col_num];}
	
	用vector的话一行代码搞定，vector<vector<int>>ary(row_num,vector<int>(col_num,0));
	
	2.使用reserve来避免不必要的重新分配
	/
