#include<stdio.h>
#include<stdlib.h>
#include"string.h"

int main() {
	
	String str1,str2,str3;
//	createString(str1,"How are you?");
//	createString(str2,"I am fine.");
	int i=1;
	while(i<=9){
		createString(str1,"abcijkghijklmnijk");
		createString(str2,"ijk");
		createString(str3,"abc123456789");
		if(i==1){
			printf("--------初始字符串--------");
			printf("\nstr1: %s",str1.ch);
			printf("\nstr2: %s",str2.ch);
			printf("\nstr3: %s",str3.ch);
		}else if(i==2){
			//-------------str2 covers str1-------------
			printf("\n\n--------字符串覆盖--------");
			printf("\n用str2覆盖str1.");
			strAssign(str1,str2);
			printf("\nstr1: %s",str1.ch);
		}else if(i==3){
			//-------------Concar string-------------
			printf("\n\n--------字符串连接--------"); 
			printf("\n连接str1和str2.");
			strConcat(str1,str2);
			printf("\nstr1: %s",str1.ch);
		}else if(i==4){
			//-------------Substring, length: 5-------------
			printf("\n\n----------子串------------");
			printf("\nstr1中1号位置开始长度为5的子串."); 
			printf("\nstr1,1,5: %s",subStr(str1,1,5).ch);
		}else if(i==5){
			//-------------compare-------------
			printf("\n\n--------字符串比较--------");
			printf("\n比较str1和str2的大小.");
			if(strCmp(str1,str2)) printf("\nStr1 == Str2");
			else printf("\nstr1 != str2.");
		}else if(i==6){
			//-------------Insert--------------
			printf("\n\n--------字符串插入--------");
			printf("\n在str1的5号位置插入str2.");
			strInsert(str1,5,str2);
			printf("\nstr1: %s",str1.ch);
		}else if(i==7){
			//-------------Delete--------------
			printf("\n\n--------字符串删除--------");
			printf("\n删除str1中3号位置开始长度为4的子串.");
			strDelete(str1,3,4);
			printf("\nstr1: %s",str1.ch);
		}else if(i==8){
			//--------------Index-------------
			printf("\n\n--------子串位置--------");
			printf("\nstr2在str1中首次出现的位置.");
			printf("\nindex: %d",strIndex(str1,str2));
		}else if(i==9){
			//-------------Rep----------------
			printf("\n\n--------字符串替换--------");
			printf("\n用str3替换str1中的str2子串.");
			strRep(str1,str2,str3);
			printf("\nstr1_changed: %s",str1.ch);
		}
		i++;
	}
	return 0;
}