#include<stdio.h>

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int x=0,y=0;
	int z[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			z[i][j]=0;
		}
	}
	int w=0,s=0,a=0,d=1;
	for(i=1;i<=n*n;i++)
	{
		if(d){
			z[x][y]=i;
			if(z[x][y]==0)
				y++;
			else{
				x++;
				d=0;s=1;w=0;a=0;
			}
			continue;
		}
		if(s){
			z[x][y]=i;
			if(z[x][y]==0)
				x++;
			else{
				y--;
				d=0;s=0;a=1;w=0;
			}
			continue;
		}
		if(a){
			z[x][y]=i;
			if(z[x][y]==0)
				y--;
			else{
				x--;
				a=0;s=0;d=0;w=1;
			}
			
			continue;
		}
		if(w){
			z[x][y]=i;
			if(z[x][y]==0)
				x--;
			else{
				y++;
				w=0;s=0;a=0;d=1;
			}
			
			continue;
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ",z[i][j]);
		}
		printf("\n");
	}
	return 0;
}



















