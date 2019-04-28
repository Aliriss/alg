#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	scanf("%lf",&n);
	double cosa=1;
	double b=1;
	int i,k=2,l=k;
	int flag=1;
	for(;;){
		for(i=0,l=k,b=1.0;i<k;i++){
			b=b*n/l;
			l--;
		}
		
		if(flag==1) flag=-1;
		else flag=1;
		cosa=cosa+flag*b;
		k=k+2;
		if(b<1e-6) break;
	}
	printf("%f",cosa);
	return 0;
}

