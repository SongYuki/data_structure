/*
	I Think I Need a Houseboat
	Fred��������ʧȥ�����ع���һ����Բ�Σ�Բ���ڣ�0,0�����ȷ����Բ������X�ᣬX����·��Ǻ�ˮ
	�ڵ�һ�꿪ʼ��ʱ����һ��Բ�����Ϊ0
	����
	����ĵ�һ����һ������������ʾ�ж��ٸ���������N��������N�У�ÿ�и����ѿ�������X��Y
	��ʾFred���ǹ�������ص�λ�ã���Щ���Ǹ���������Ӣ��Ϊ��λ��Y����Ϊ�����������(0,0)
	���
	��ÿ������Ĳ������������һ��
	��һ�е���ʽΪProperty N:This property will begin eroding in year Z
	����N�ǲ��������ı�ţ���1��ʼ������Z��ʾ���������ڵ�Z�������ʱ��Ҫ�䵽��Բ���У���1��ʼ������Z������һ������
	�����һ����������֮�����END OF OUTPUT
*/

/*
	��i����������(Xi,Yi)��Բ��(0,0)���ɵİ�Բ���Ϊ���ر��͵ķ�Χ��
	����ÿ�����50ƽ��Ӣ�����أ�������������������û(Xi,Yi)�����ӦΪ����(��Բ���/50)����С����
	��������ȡ������ceil(x) ����������ȡ������floor(x) 
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












