#include<stdio.h>

int main()
{
	char n[26],m[256];
	gets(n);
	gets(m)
	int a[n];
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int k=0,s=0;
	for(int i=0;i<n-1;i++){
		k=i;
		for(int j=i+1;j<n;j++){
			if(a[k]<a[j]) k=j;
		}
		s=a[k];
		a[k]=a[i];
		a[i]=s;
	}
	int min=n<m?n:m;
	for(int i=0;i<min;i++)
		printf("%d ",a[i]);
	return 0;
}
