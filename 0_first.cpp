#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void sort(int *p,int n);
void change(int*p,int *q);
void init_data(int *p,int n);
void user_operation(int *p,int n);
void print(int *p,int n);
int main(){
	int n=5,i=0;
	char c;
	int *p=(int *)calloc(n,sizeof(int));
	init_data(p,n);
	sort(p,n);
	user_operation(p,n);
	return 0;
}
void init_data(int *p,int n){
	srand(time(NULL));
	for(int i=0;i<n;i++){
		*(p+i)=rand()%100;
	}
}
void sort(int *p,int n){
	int i=0,j=0;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(p[i]>p[j]){
				change(&p[i],&p[j]);
			}
		}
	}
}
void change(int *p,int *q){
	int x=*p;
	*p=*q;
	*q=x;
}
void user_operation(int* p,int n){
	int i=0;
	printf("初始数组：");
	print(p,n);
	printf("\n");
	while(1){
		p=(int *)realloc(p,(++n)*sizeof(int));
		printf("请输入你要插入的数：");
		scanf("%d",p+(n-1));
		getchar();
		sort(p,n);
		printf("插入后的数组：");
		print(p,n);
		printf("\n是否要继续(y/n)");
		char c=getchar();
		getchar();
		if(c=='n' || c=='N') break;
	}
	printf("最终数组：");
	print(p,n);
	printf("\n");
}
void print(int *p,int n){
	int i=0;
	for(i=0;i<n;i++){
		printf("%d ",*(p+i));
	}
}


