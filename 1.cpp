//题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//1.程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去掉不满足条件的排列。

#include<stdio.h>
int main()
{
	int a,b,c;
	int num=0;
	for(a=1;a<5;a++)
	{
		for(b=1;b<5;b++)
			for(c=1;c<5;c++)
		{
			if(a!=b&&a!=c&&b!=c){
				printf("%d%d%d\t",a,b,c);
				num++;
			}
		}
		printf("\n");
	}
	printf("total is:%d",num);
	return 0;
}
