#include<stdio.h>

void print_descending(int i, int j, int k);

int main(int argc, char *argv[])
{
	int i, j, k;
	
	i=234;
	j=787;
	k=1908;
	
//	printf("依次输入的数据为:\n");
//	scanf("%d,%d,%d", &i, &j, &k);
	printf("从大到小的顺序为:");

	print_descending(i, j, k);

	printf("\n");
	return 0;
}

void print_descending(int i, int j, int k)
{
	int tmp;
//	scanf("%d,%d,%d",&i,&j,&k);
	if (i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}
	if (j<k)
	{
		tmp = j;
		j = k;
		k = tmp;
	}
	if (i<j)
	{
		tmp = i;
		i = j;
		j = tmp;
	}

	printf("%d %d %d\n", i, j, k);
}


