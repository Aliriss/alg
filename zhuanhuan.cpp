/*
问题描述
编制密码转换方式：大写字母-->小写字母，小写字母-->大写字母，数字-->*，其它符号-->@。
输入说明
输入函数使用scanf，格式%c控制。
输出说明
输出密码转换后的结果。
输入样例
A2c&
输出样例
a*C@
提示信息
输入四位密码字符，如A2c&
*/
#include<stdio.h>
#include<ctype.h>
int main(){
	char a[5]={'0'};
	gets(a);
	int i;
	for(i=0;i<4;i++){
		if(a[i]<='Z'&&a[i]>='A') a[i]=tolower(a[i]);
		else if(a[i]<='z'&&a[i]>='a') a[i]=toupper(a[i]);
		else if(a[i]<='9'&&a[i]>='0') a[i]='*';
		else a[i]='@';
	}
	puts(a);
	
	return 0;
}
