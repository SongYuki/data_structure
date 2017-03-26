/*二重循环估算*/

#include<stdio.h>

int func(int a[],int len)
{
    int i = 0;
    int j = 0;
    int s = 0;

    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            printf("%d * %d\n",i,j);
            s += i*j;
        }
    }
    return s;
}

int main()
{
    int array[] = {1,2,3,4,5};
    printf("%d\n",func(array,5));
    return 0;
}
