#include<stdio.h>

int plus(int a,int b)
{
	return a+b;
}
int minus(int a,int b)
{
	return a-b;
}
void cal(int (*f)(int,int))
{
	printf("\n%d",(*f)(2,3));
}
int main()
{
	cal(plus);
	cal(minus);
	
	return 0;
}
