#include<stdio.h>
#include<stdlib.h>

void helper(int *pa, int *pb, int **sum)
{
	int res = *pa;
	res+=*pb;
	*sum = &res;
}

int main()
{
	int a = 3;
	int b = 5;
	int *res = malloc(4);

	helper(&a, &b, &res);
	printf("%d %d %d\n",a,b,*res);
	free(res);
}
