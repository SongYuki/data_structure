void polyvalue()
{
	float ad;
	float *p = a;
	printf("Input number of terms:");
	scanf("%d", &n);
	printf("Input the %d coefficients from a0 to a%d:\n", n, n);
	for (i = 0; i <= n; i++) scanf("%f", p++);
	printf("Input value of x:");
	scanf("%f", &x);
	p = a; xp = 1; sum = 0;//xp用于存放x的i次方
	for (i = 0; i <= n; i++)
	{
		sum += xp*(*p++);
		xp *= x;
	}
	printf("Value is: %f", sum);
}	//polyvalue
