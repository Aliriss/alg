#include<stdio.h>

int main(){
	int m,n;
	printf("������m��ֵ��");
	scanf("%d",&m);
	printf("������n���ˣ�");
	scanf("%d",&n);
	int peo[n],i;
	for(i=0;i<n;i++){
		peo[i]=i+1;
	}
	int sum=n;
	int j=0;//j���ڼ��� 
	while(1){
		for(i=0;i<n;i++){
			if(peo[i]!=0){
				j++;
				if(j==m){
					if(sum==1){
						printf("ʤ�����ǣ� %d",peo[i]);
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
