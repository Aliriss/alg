#include<stdio.h>
#include<math.h>
int number(int num);
int main()
{
	int i,a,b,j,count,g,h,m,l;
	int num=0;
	int w[100]={0};
	scanf("%d",&count);
for(h=0;h<count;h++)
{
    g=0;
	scanf("%d %d",&a,&b);
	if(a<100)a=100;
	for(i=a;i<=b;i++)
	{
		m=i;
		l=number(m);
		for(j=0;m!=0;)
	{
		j=j+pow(m%10,l);
		m=m/10;
	}
	if(j==i)g=g+1;
	}
	w[h]=g;
}

	for(j=0;j<count;j++)
	{
		printf("%d\n",w[j]);
	}
	return 0;
 } 
int number(int num)
{
int i=0;
do
{
	num=num/10;
	i++;
}
while(num!=0);
return(i);}
