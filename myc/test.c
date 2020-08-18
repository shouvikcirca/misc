#include<stdio.h>
#include<math.h>

float i;

int someFun()
{
	
	static int a;
	int l;
	printf("Value of l:%d\n",l);
	a+=1;
	return a;
}

int moreFun(int a)
{
	printf("More Fun:%d\n",a);
}

int main()
{
	printf("Hello\n");

//	float a = 3.14;
//	float b = 1.21;
//	float c = fmod(a,b);
//	printf("%f\n",c);


	int b = someFun();
	int c = someFun();
	int d = someFun();
	int e;
	printf("Enter a number\n");
	scanf("%d",&e);
	printf("%d\n",e);
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);

	//extern int f;
	//printf("%d\n",f);

	auto int g;
	printf("%d\n",g);

	register int h;
	printf("%d\n",h);

	printf("%f\n",i);

        moreFun(3.14);
	
//auto and local: defalut value is garbage
//register: default value is 0
//static: default value is 0
//extern: no default value, will throw error
//global variable: default value is 0

	
}
