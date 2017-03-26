# 游戏之乐

标签（空格分隔）： 编程之美

---
**Question**:
写一个程序，让用户来决定windows task manager的CPU占用率，程序越精简越好，计算机语言不限。
例如，可以实现下面三种情况
1.CPU的占用率固定在50%为一条直线
2.CPU的占用率为一条直线，但是具体占用率由命令行参数决定（参数范围：1-100）
3.CPU的占用率状态是一个正弦曲线

**Analyze**:
通过task manager的进程process一栏可以看到，System Idle Process占用了CPU空闲的时间
系统中的进程在等待用户输入或者等待某些事件的发生或者主动进入休眠状态时，它们会“闲下来”

在task manager的一个刷新周期内，CPU忙（执行应用程序）的时间和刷新周期总时间的比率，就是CPU的占用率。任务管理器中显示的是每个刷新周期内CPU占用率的统计平均值。
我们可以写一个程序，让它在task manager的刷新期间内一会儿忙一会儿闲，然后通过调节忙/闲的比例，就可以控制任务管理器中显示的CPU占用率

**answer:**
**simple:**
使CPU在一段时间内跑busy/idle两个不同的循环loop，从而通过不同的时间比例，来调节CPU的使用率
busy loop可以通过执行空循环来实现，idle可以通过Sleep()来实现
对于一个空循环for(i=0;i<n;i++)该如何来估算这个最合适的n值呢？CPU执行的是机器指令而最接近于机器指令的语言是汇编语言，可以先把空循环简单写成如下汇编代码后进行分析：
loop:
mov dx i;
inc dx;
mov i dx;
cmp i n;
jl loop;

假设这段代码运行的CPU是2.4Ghz(2.4*10^9个时钟周期每秒)现代CPU每个时钟周期可以执行两条以上的代码取平均值两条(（2.4*10^9）*2)/5=9.6*10^8(循环/秒)也就是说CPU一秒钟可以运行这个空循环9.6*10^8次
尝试降低两个数量级，n=9.6*10^6睡眠时间相应改为10mm(Sleep(10))用10毫秒是因为比较接近windows的调度时间片

    int main()
    {
        for(;;)
        {
            for(int i=0;i<9600000;i++)
            {
                ;
            }
 Sleep(10);
        }
        return 0;
    }


**Notice:**
1.尽量减少sleep/awake的频率，减少操作系统内核调度程序的干扰
2.尽量不要调用system call(I/O这些privilege instruction)因为它也会导致很多不可控的内核运行时间

**Answer：**
**Advanced：**
GetTickCount()得到“系统启动到现在”所经历时间的毫秒值，最多能统计到49.7天，可以利用GetTickCount()来判断busy loop要循环多久

    int busyTime = 10;//10ms
    int idleTime = busyTime://same ratio will lead to 50% cpu usage
    Int64 statrtTime = 0;
    while(true)
    {
        startTime = GetTickCount()
        //busy loop
        while(GetTickCount()-startTime<=busyTime)
        {
            ;
        }
        //idle loop
        Sleep(idleTime);
    }
    
    
**Tips:**
Perfmon是从Windows NT开始就包含在Windows管理工具组中的专业检测工具之一。
可以通过写程序查询Perfmon的值，Microsoft.Net Framework提供了PerformanceCounter这一对象，可以方便地得到当前各种性能数据，包括CPU的使用率

**Answer:**
**Dynamic:**

    //C# code
    static void MakeUsage(float level)
    {
        PerformanceCounter p = new PerformanceCounter("Processor","% Processor Time","_Total");
        while(true)
        {
            if(p.NextValue()>level)
            {
                System.Threading.Thread.Sleep(10);
            }
        }
    }



使用这个解法能方便地处理各种CPU使用率参数。


**Answer:**
**Sin Curv Line:**

    //C++ code to make task manager generate sine graph
    #include"Windows.h"
    #include"stdlib.h"
    #include"math.h"
    const double SPLIT =0.01;
    const int COUNT =200;
    const double PI = 3.14159265;
    const int INTERVAL = 300;
    
    int _tmain(int argc,_TCHAR* argv[])
    {
        DWORD busySpan[COUNT];//array of busy times
        DWORD idleSpan[COUNT];//array of idle times
        int half = INTERVAL/2;
        double radian = 0.0;
        for(int i=0;i<COUNT;i++)
        {
            busySpan[i]=(DWORD)(half+(sin(PI*radian)*half));
            idleSpan[i]=INTERVAL-busySpan[i];
            radian += SPLIT;
        }
        DWORD startTime = 0;
        int j = 0;
        while(true)
        {
            j = j%COUNT;
            startTime = GetTickCount();
            while((GetTickCount()-startTime)<=busySapn[j])
            {
                ;
            }
            Sleep(idleSpan[j]);
            j++;
        }
        return 0;
    }
    
    

**FutherMore:**
多CPU的问题首先需要获得系统的CPU信息。可以使用GetProcessorInfo()获得多处理器的信息，然后指定进程在哪一个处理器上运行。其中指定运行使用的是SetThreadAffinityMask()函数

还可以使用RDTSC指令获取当前CPU核心运行周期数
在x86平台上定义函数
inline _int64 GetCPUTickCount()
{
    _asm
    {
        rdtsc;
    }
}

在x64平台上定义
#define GetCPUTickCount() _rdtsc()

**使用CallNtPowerInformation API得到CPU频率，从而将周期数转化为毫秒数**

    _PROCESSOR_POWER_INFOMATION info;
    
    CallNTPowerInfomation(11,//query processor power information
    NULL, //no input buffer
    0,//input buffer size is zero
    &info,//output buffer
    Sizeof(info));  //outbuf size
    
    _int64 t_begin = GetCPUTickCount();
    //do something
    _int64 t_end = GetCPUTickCount();
    double millisec = ((double)t_end-(double)t_begin)/(double)info.CurrentMhz;
    
    
**RDTSC指令读取当前CPU的周期数，在多CPU系统中，这个周期数在不同的CPU之间基数不同，频率也有可能不同。用从两个不同的CPU得到的周期数作计算会得出没有意义的值。如果线程在运行中被调度到了不同的CPU，就会出现上述情况。可用SetThreadAffinityMask避免线程迁移。另外，CPU的频率会随系统供电及负荷情况有所调整。**

**Conclude:**
了解当前线程/进程/系统效能的API大致有以下这些
1.Sleep() -- 这个方法能让当前线程“停”下来
2.WaitForSingleObject() -- 自己停下来，等待某个事件发生。
3.GetTickCount()--获得时钟周期
4.QueryPerformanceFrequency()/QueryPerformanceCounter()--让你访问精度更高的CPU数据
5.timeGetSystemTime()--是另一个得到高精度时间的方法
6.PerformanceCounter -- 效能计数器
7.GetProcessorInfo()/SetThreadAffinityMask()遇到多核问题，这两个方法帮你更好控制CPU
8.GetCPUTickCount()--拿到CPU核心运行周期数


**Question**
中国象棋将帅问题
请写出一个程序，输出A,B所有合法位置。要求在代码中只能使用一个变量

**Analyze**
由于本题要求只能使用一个变量，所以必须首先想清楚在写代码的时候，有哪些信息需要存储，并且尽量高效率地存储信息
（遍历A的位置
    遍历B的位置
        判断A,B的位置组合是否满足要求
            如果满足，则输出）
    事实上，对本题来说，每个子只需要九个数字就可以表达它的全部位置
    可以把一个byte类型的变量（设为b）分为两部分，用前面的4bit表示A的位置，用后面的4bit表示B的位置，那么4个bit可以表示16个数，这已经足够了。
    **问题在于:如何使用bit级的运算将数据从这一byte变量的左边和右边分别存入和读出**
    **最后的挑战是如何在不声明其他变量约束的前提下创建一个for循环。可以重复利用1byte的存储单元，把它作为循环计数器并用前面提到的存取和读入技术进行操作。还可以用宏来抽象化代码**
    for(LSET(b,1);LGET(b)<=GRIDW*GRIDW;LSET(b,(LGET(b)+1)))
    
    #define HALF_BITS_LENGTH 4
    //记忆存储单元长度的一半 4bit
    #define FULLMASK 255
    //一个全部bit的mask 在二进制表示中它是11111111
    #define LMASK(FULLMASK<<HALF_BITS_LENGTH)
    //左bits的mask在二进制表示中它是11110000
    #define RMASK(FULLMASK>>HALF_BITS_LENGTH)
    //右bits的mask在二进制表示中，表示00001111
    #define RSET(b,n)(b=((LMASK&b)^n))
    //将b的右边设置成n
    #define LSET(b,n)(b=(RMASK&b)^(n<<HALF_BITS_LENGTH))
    //将b的左边设置为n
    #define RGET(b)(RMASK &b)
    //得到b的右边的值
    #deine LGET(b)((LMASK&b)>>HALF_BITS_LENGTH)
    //得到b的左边的值
    #define GRIDW 3
    //表示将帅移动范围的行宽度
    #include<stdio.h>
    #define HALF_BITS_LENGTH 4
    #define FULLMASK 255
    #define LMASK(FULLMASK<<HALF_BITS_LENGTH)
    #define RMASK(FULLMASK>>HALF_BITS_LENGTH)
    #define RSET(b,n)(b=((LMASK&b)^n)
    #define LSET(b,n)(b=((RMASK&b)^(n<<HALF_BITS_LENGTH)))
    #define RGET(b)(RMASK&b)
    #define LGET(b)((LMASK&b)>>HALF_BITS_LENGTH)
    #define GRIDW 3
    int main()
    {
        unsigned char b;
        for(LSET(b,1);LGET(b)<=GRIDW*GRIDW;LSET(b,(LGET(b)+1)))
        for(RSET(b,1);RGET(b)<=GRIDW*GRIDW;RSET(b,(RGET(b)+1)))
        if(LGET(b)%GRIDW!=RGGET(b)%GRIDW)
        printf("A=%d,B=%d\n",LGET(b),RGET(b));
        return 0;
    }
    
    
    
**Adevanced**

    BYTE i=81;
    while(i--)
    {
        if(i/9%3==i%9%3)
        continue;
        printf("A=%d,B=%d\n",i/9+1,i%9+1);
    }
    
    struct{
        unsigned char a:4;
        unsigned char b:4;
        }i;
        for(i.a=1;i.a<=9;i.a++)
        for(i.b=1;i.b<=9;i.b++)
        if(i.a%3==i.b%3)
        printf("A=%d,B=%d\n",i.a,i.b);
        