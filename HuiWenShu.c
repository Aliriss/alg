#include<stdio.h>

int shuwei(long long int n){
	long long int i=n;
	int amount=0;
	for(;i!=0;i=i/10){
		amount++;
	}
	return amount;
}
void judge(long long int n){
	int weishu=shuwei(n);
	int wei[weishu];
	for(int i=0;i<=weishu;i++){
		wei[i]=n%10;
		n=n/10;
	}
	int k=0,l=1;
	for(int i=0,j=weishu-1;i<weishu/2;i++,j--){
		if(wei[i]!=wei[j]){
			printf("no\n");
			l=0;
			break;
		}
	}
	if(l){
		for(int i=0;i<weishu;i++){
			k+=wei[i];
		}
		printf("%d\n",k);
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	long long int a[n];
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++){
		judge(a[i]);
	}
	
	return 0;
}
