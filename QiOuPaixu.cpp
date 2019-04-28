

/*
问题描述
给定N个不同的整数，要求对这N个整数按如下规则排序并输出。 
规则一：所有的偶数排在奇数前面。 
规则二：在规则一的前提下按照从大到小的顺序排序。 
输入说明
只有一组数据。数据由两行构成，第一行为整数n（n<=100），表示待排序整数的数量。第二行是n个整数，每个整数的取值区间都为[-32768~32767]，整数之间以空格间隔。
输出说明
在一行输出排好序的整数，整数之间以空格间隔，然后换行。
输入样例
5 
1 2 3 4 5 
输出样例
4 2 5 3 1
*/




#include<stdio.h>
void sort(int a[],int n);
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int i=0,j=0;
    int s;
    int x=0,y=0;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    
	for(i=0;i<n;i++){
		if(a[i]%2==0){
			j++;
		}
	}
	int b[j],c[n-j];
	for(i=0;i<n;i++){
		if(a[i]%2==0){
			b[x]=a[i];
			x++;
		}else{
			c[y]=a[i];
			y++;
		}
		
	}
	sort(b,j);
	
	sort(c,n-j);
//    for(i=0;i<j;i++)
//    printf("%d ",b[i]);
//    for(i=0;i<n-j;i++)
//    printf("%d ",c[i]);
    return 0;
}
void sort(int a[],int n){
	int i,j,s;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++)
		if(a[j]>a[i]){
			s=a[i];
			a[i]=a[j];
			a[j]=s;
		}
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
