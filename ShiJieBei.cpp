#include<stdio.h>
typedef struct stu{
	char name[20];
	int w;//sheng chang shu 
	int e;//ping ju shu 
	int f;//fu chang shu
	int s;//jing qiu shu 
	int ls;//shi qiu shu
}STU;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fflush(stdin);
	STU student[n];
	int fen[n];
	for(int i=0;i<n;i++){
		scanf("%s%d%d%d%d%d",student[i].name,&(student[i].w),&(student[i].e),&(student[i].f),&(student[i].s),&(student[i].ls));
		fen[i]=(student[i].w)*3+(student[i].e);
	}
	STU s;
	int k;
	int l;
	for(int i=0;i<n-1;i++){
		k=i;
		for(int j=i+1;j<n;j++){
			if(fen[i]<fen[j]||(fen[i]==fen[j]&&(student[i].s-student[i].ls)<(student[j].s-student[j].ls))) k=j;
		}
		s=student[i];
		student[i]=student[k];
		student[k]=s;
		l=fen[i];
		fen[i]=fen[k];
		fen[k]=l;
	}
	for(int i=0;i<n;i++){
		printf("%d %s %d %d\n",i+1,student[i].name,fen[i],student[i].s-student[i].ls);
	}
	return 0;
}

