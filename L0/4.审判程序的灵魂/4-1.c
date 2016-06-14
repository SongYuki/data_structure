/*
 * 最好与最坏
 * 最好情况是执行一次，复杂度为O(1)
 * 最坏情况是执行n次，复杂度是O(n)
 */
#include<stdio.h>

int search(int array[],int length,int n)
{
    int ret = -1;
    int i = 0;

    for(i=0;i<length;i++)
    {
        if(array[i]==n)
        {
            ret = i;
            break;
        }
    }
    return ret;
}

int main()
{
    int array[5] = {1,2,3,4,5};

    printf("%d\n",search(array,5,1));
    printf("%d\n",search(array,5,5));

    return 0;
}
