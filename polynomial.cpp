//设计函数分别求两个一元多项式的乘积与和。
//输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
//输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
#include<stdio.h>
typedef struct polynomial{
	int coefficient=0;   //系数 
	int exponent=0;     //指数 
}pol;
void sums(pol a[],int n,pol b[],int m);     //求和 
void product(pol a[],int n,pol b[],int m);  //乘积 
void merges(pol a[],int n);                //合并 
void testPrint(pol a[],int n);
int main()
{
	int n,m;
	scanf("%d",&n);
	pol a[n];
	int i=0,j=0;
	for(i=0;i<n;i++){
		scanf("%d%d",&a[i].coefficient,&a[i].exponent);
	}
	scanf("%d",&m);
	pol b[m];
	for(i=0;i<m;i++){
		scanf("%d%d",&b[i].coefficient,&b[i].exponent);
	}
	
	product(a,n,b,m);
	printf("\n");
	sums(a,n,b,m);
	
	return 0;
}
void testPrint(pol a[],int n){
	int i=0,j=0,e=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i].exponent<a[j].exponent){
				e=a[i].exponent;
				a[i].exponent=a[j].exponent;
				a[j].exponent=e;
				e=a[i].coefficient;
				a[i].coefficient=a[j].coefficient;
				a[j].coefficient=e;
			}
		}
	}
	for(i=0;i<n;i++){
		if(a[i].coefficient!=0)
			//printf("\n%d*x^%d",a[i].coefficient,a[i].exponent);
			printf("%d %d ",a[i].coefficient,a[i].exponent);
	}
}
void merges(pol a[],int n){
	int i=0,j=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i].exponent==a[j].exponent){
				a[i].coefficient+=a[j].coefficient;
				a[j].coefficient=0;
				a[j].exponent=0;
			}
		}
	}
	testPrint(a,n);
} 
void sums(pol a[],int n,pol b[],int m){
	int i=0,j=0,k=0;
	pol c[n+m];
	while(i<n){
		while(j<m){
			if(a[i].exponent==b[j].exponent){
				c[k].exponent=a[i].exponent;
				c[k].coefficient=a[i].coefficient+b[j].coefficient;
				j++,i++,k++;
			}else if(a[i].exponent>b[j].exponent){
				c[k].exponent=a[i].exponent;
				c[k].coefficient=a[i].coefficient;
				k++,i++;
				break;
			}else{
				c[k].exponent=b[j].exponent;
				c[k].coefficient=b[j].coefficient;
				k++,j++;
			}
		}
		c[k].coefficient=a[i].coefficient;
		c[k].exponent=a[i].exponent;
		k++,i++;
	}
	merges(c,k);
	
}
void product(pol a[],int n,pol b[],int m){
	int i=0,j=0,k=0;
	pol c[n*m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			c[k].coefficient=a[i].coefficient*b[j].coefficient;
			c[k].exponent=a[i].exponent+b[j].exponent;
			k++;
		}
	}
	merges(c,n*m);
} 
