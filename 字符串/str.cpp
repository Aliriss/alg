#include<stdio.h>
#include<stdlib.h>
#include"string.h"
#define N 10
int main() {
	String str1;
	String str2;
	initString(str1,10);
	initString(str2,10);
	char *p=str1.ch;
	int i=0;
	for(i=1;i<str1.length;i++){
		*p='s';p++;
	}
	*p='\0';
	p=str2.ch;
	printf("\nstr1: %s",str1.ch);
	for(i=1;i<str2.length;i++){
		*p='2';p++;
	}
	*p='\0';
	printf("\nstr2: %s",str2.ch);
	
	//-------------str2 covers str1-------------
	//strAssign(str1,str2);
	
	//-------------Concar string-------------
	//strConcat(str1,str2);
	
	//-------------Substring, length: 5-------------
	//String S=subStr(str1,1,5);
	
	//-------------compare-------------
//	if(strCmp(str1,str2)) printf("\nStr1 == Str2");
//	else printf("\nStr1 != Str2.");
	//printf("\nstr1: %s",S.ch);
	
	strInsert(str1,5,str2);
	printf("\nstr1: %s",str1.ch);
	return 0;
}
