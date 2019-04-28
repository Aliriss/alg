#include<stdio.h>
int main()
{
	int i,j,a,b,total;
	for(i=6;i;i++)
	{
		for(j=0,total=i;j<5;j++){
			if(total%5!=1){
				break;
			}
			total=total-total/5-total%5;
			//printf("%d ",total);
			if(j==4){
				if(total%5==0){
					j++;
					break;
				}
			}
		}
		//printf("\n");
		if(j==5)
		{
			break;
		}
	}
	printf("%d",i);
	return 0;
}
