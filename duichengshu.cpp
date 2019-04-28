#include<stdio.h>
int is(long long int n,int x){
	int i=0;
	long long int b=n;
	int a[x];
	for(i=0;i<x;i++){
		a[i]=b%10;
		b=b/10;
	}
	x=x-1;
	for(i=0;i<x+1;i++){
		if(a[i]!=a[x--]){
			return 0;
		}
	}
	return 1;
}
int main()
{
	long long int n;
	scanf("%d",&n);
	int a;
	int i=1;
	for(a=n;a/10!=0;a=a/10){
		i++;
	}
	printf("%d",is(n,i));
	return 0;
}
