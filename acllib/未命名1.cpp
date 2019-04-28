#include<stdio.h>
int main()
{
	int a=22;int z,q,x,g,f=a;int i=2;
	for(z=0;a!=0;)
			{
				z=a%10;
				printf(" %d \n",z);
				q=1;
				for(i;i>0;--i)
				{
					q*=z;
					printf("%d ",q);
					x+=q;
				}
//				printf("%d",a);
				a=a/10;
//				printf(" %d\n",a);
				if(x==f) g++;
			}
	return 0;
}
