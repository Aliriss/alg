/*
��������
��������ת����ʽ����д��ĸ-->Сд��ĸ��Сд��ĸ-->��д��ĸ������-->*����������-->@��
����˵��
���뺯��ʹ��scanf����ʽ%c���ơ�
���˵��
�������ת����Ľ����
��������
A2c&
�������
a*C@
��ʾ��Ϣ
������λ�����ַ�����A2c&
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
