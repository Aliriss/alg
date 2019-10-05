#include<stdio.h>

int main(){
	int m,n;
	printf("请输入m的值：");
	scanf("%d",&m);
	printf("请输入n个人：");
	scanf("%d",&n);
	int peo[n],i;
	for(i=0;i<n;i++){
		peo[i]=i+1;
	}
	int sum=n;
	int j=0;//j用于计数 
	while(1){
		for(i=0;i<n;i++){
			if(peo[i]!=0){
				j++;
				if(j==m){
					if(sum==1){
						printf("胜利者是： %d",peo[i]);
						return 0;
					}
					peo[i]=0;
					sum--;
					j=0;
				}
			}
		}
	}
	return 0;
} 
