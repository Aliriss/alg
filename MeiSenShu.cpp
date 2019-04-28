#include<stdio.h>
bool h(long long int c){
	if(c<=2) return 1;
    for(long long int i=c-1;i>1;i--){
        if(c%i==0) return 0;
    }
	return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0||n==1) {
    	printf("0");
    	return 0;
	}
    long long int c=1;
    for(int i=1;i<=n;i++){
        c*=2;
    }
    if(h(c-1)) printf("1");
    else printf("0");
    return 0;
}
