#include<stdio.h>

int main() {
	int m,n;
	printf("please enter m: ");
	scanf("%d",&m);
	printf("please enter the number of people: ");
	scanf("%d",&n);
	int peo[n],i;
	for(i=0; i<n; i++) {
		peo[i]=i+1;
	}
	int sum=n;
	int j=0;//j???????
	while(1) {
		for(i=0; i<n; i++) {
			if(peo[i]!=0) {
				j++;
				if(j==m) {
					if(sum==1) {
						printf("the victor is %d",peo[i]);
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
