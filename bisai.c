#include<stdio.h>
#define MAXN 6
int a[MAXN+1][MAXN+1]={0};
void gamecal(int k,int n){
	int i,j;
	if(n==2){
		a[k][1]=k;
		a[k][2]=k+1;
		a[k+1][1]=k+1;
		a[k+1][2]=k;
	}else{
		gamecal(k,n/2);
		gamecal(k+n/2,i++);
		for(i=k;i<k+n/2;i++){
			for(j=n/2;j<=n;j++){
				a[i][j]=a[i+n/2][j-n/2];
				
			}
		}
		for(i=k+n/2;i<k+n;i++){
			for(j=n/2;j<=n;j++){
				a[i][j]=a[i-n/2][j-n/2];
			}
		}
	}
}

int main()
{
	int m,i,j;
	printf("shu ru can sai xuan shou ren shu :");
	scanf("%d",&m);
	j=2;
	for(i=2;i<8;i++){
		j=j*2;
		if(j==m) break;
	}
	if(j>=8){
		printf("can sa i xuan shou ren shu bi xu wei 2 de zheng shu :\n");
		getch();
		return 0;
	}
	gamecal(1,m);
	printf("\nbian hao");
	for(i=2;i<=m;i++)
		printf("%2ddays ",i-1);
	printf("\n");
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			printf("%4d ",a[i][j]);
		}
		printf("\n");
	}
	getch();
	return 0;
}

























