#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char * s);
int main(){
	char s[]="";
	printf("String: %s\nLength: %d ",s,strlen(s));
	printf("\nLength of longest substring:  %d",lengthOfLongestSubstring(s));
	return 0;
}
int lengthOfLongestSubstring(char * s){
	int i=0,j=0;
	int x=0,sum=x;
	int n=i;
	int flag=1;
	//if(strlen(s)==0) return 0;
	for(i=0;i<strlen(s);i++){
		if(x==0) {
			n=i;
			x++;
			flag=0;
		}
		for(j=n;j<i;j++){
			if(s[j]==s[i]){
				x=1;
				flag=0;
				i=j+1;
				n=i;
				break;
			}else{
				flag=1;
			}
		}
		if(flag==1){
			x++;
		}
		if(sum<x) {
			sum=x;	
		}
	}
	return sum;
}
