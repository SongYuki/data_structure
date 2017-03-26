/*
	I Think I Need a Houseboat
	Fred发现正在失去的土地构成一个半圆形，圆心在（0,0）二等分这个圆的线是X轴，X轴的下方是河水
	在第一年开始的时候，这一半圆的面积为0
	输入
	输入的第一行是一个正整数，表示有多少个测试用例N，后面有N行，每行给出笛卡尔坐标X和Y
	表示Fred考虑购买的土地的位置，这些数是浮点数，以英里为单位，Y坐标为负。不会给出(0,0)
	输出
	对每个输入的测试用例，输出一行
	这一行的形式为Property N:This property will begin eroding in year Z
	其中N是测试用例的编号（从1开始计数）Z表示他的土地在第Z年结束的时候要落到半圆形中（从1开始计数）Z必须是一个整数
	在最后一个测试用例之后，输出END OF OUTPUT
*/

/*
	第i个测试用例(Xi,Yi)与圆心(0,0)构成的半圆面积为土地被淹的范围。
	由于每年减少50平方英里土地，而年份是整数，因此淹没(Xi,Yi)的年份应为大于(半圆面积/50)的最小整数
	采用向上取整函数ceil(x) 而不是向下取整函数floor(x) 
*/ 

#include<stdio.h>
#include<math.h>
#define M_PI 3.14159265
int num_props;
float x,y;
int i;
double calc;
int years;

int main(void)
{
	scanf("%d",&num_props);
	for(i=1;i<=num_props;i++)
	{
		scanf("%f %f",&x,&y);
		
		calc = (x*x+y*y)*M_PI/2/50;
		years = ceil(calc);
		printf("Property %d:This property will begin eroding in year %d.\n",i,years);
	}
	printf("END OF OUTPUT.\n");
}












