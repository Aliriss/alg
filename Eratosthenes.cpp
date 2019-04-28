#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n-1];
	int i;
	for(i=0;i<n-1;i++){
		a[i]=i+2;
	}
	int j;
	int k=0;
	int l;
	for(i=0;i<n-1;i++){
		for(k;k<n-1;k++){
			if(a[i]) {
				j=a[i];
		     	k++;
				break;
	    	}
	   }
	   for(l=k;l<n-1;l++)
		if(a[l]%j==0) {
			a[l]=0;
		}
	}
	for(i=0;i<n-1;i++){
		if(a[i])
		printf("%d\n",a[i]);
	}
	return 0;
}
