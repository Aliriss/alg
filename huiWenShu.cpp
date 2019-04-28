#include<stdio.h>

int main()
{
	int judge(long long a);
	int n;
	scanf("%d",&n);
	int i=0;
	long long a[n];
	for(i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	int c=0;
	for(i=0;i<n;i++){
		if(a[i]==0){printf("0\n");continue;}
		if(c=judge(a[i])) {
			printf("%d\n",c);
		}else{
			printf("no\n");
		}
	}
	return 0;
}
int judge(long long a)
{
	if(a/10==0) return a;
	int i=0;
	int index=0;
	int b[100]={0};
	do{
		b[index]=a%10;
		index++;
	}while((a=a/10)!=0);
	int c=0;
	for(i=0;i<index/2;i++){
		
		if(b[i]==b[index-i-1]) c=1;
		else break;
	}
	int sum=0;
	if(c){
		for(i=0;i<index;i++)	sum+=b[i];
		return sum;
	}
	return 0;
}

