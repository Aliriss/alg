#include<stdio.h>
struct steam
{
	char name[20];
	int score;
	int ball;
};
int main()
{
	int a,b,c;
	int i,j,k;
	int m[5]={0};
	struct steam cy[20],t;
	scanf("%d %d",&a,&b);
	for(c=0;c<a;c++)
	{
		scanf("%s %d %d %d %d %d",cy[c].name,&m[0],&m[1],&m[2],&m[3],&m[4]);
		cy[c].score=m[0]*3+m[1]*1;
		cy[c].ball=m[3]-m[4];
	}
	for(i=0;i<a-1;i++)
	{
		k=i;
		for(j=i+1;j<a;j++)
			if(cy[j].score>cy[k].score||((cy[j].score==cy[k].score)&&cy[j].ball>cy[k].ball))
				k=j;
		t=cy[k];cy[k]=cy[i];cy[i]=t;
	}
	for(c=0;c<b;c++)
		printf("%d %s %d %d\n",c+1,cy[c].name,cy[c].score,cy[c].ball);
	return 0;
}
