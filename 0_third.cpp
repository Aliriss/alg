#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	double a;
	double b;
}Comp,* LinkList;

void jia(LinkList x1,LinkList x2,LinkList x3);
void jian(LinkList x1,LinkList x2,LinkList x3);
void cheng(LinkList x1,LinkList x2,LinkList x3);
void chu(LinkList x1,LinkList x2,LinkList x3);
int main(){
	LinkList x1=(LinkList)malloc(sizeof(Comp));
	LinkList x2=(LinkList)malloc(sizeof(Comp));
	LinkList x3=(LinkList)malloc(sizeof(Comp));
	printf("请输入第一个复数的实部和虚部：");
	scanf("%lf%lf",&(x1->a),&(x1->b));
	printf("请输入第二个复数的实部和虚部：");
	scanf("%lf%lf",&(x2->a),&(x2->b));
	printf("x1: %.2f%+.2fi\n",x1->a,x1->b);
	printf("x2: %.2f%+.2fi\n",x2->a,x2->b);
	jia(x1,x2,x3);
	printf("x1 + x2 = %.2f%+.2fi\n",x3->a,x3->b);
	jian(x1,x2,x3);
	printf("x1 - x2 = %.2f%+.2fi\n",x3->a,x3->b);
	cheng(x1,x2,x3);
	printf("x1 * x2 = %.2f%+.2fi\n",x3->a,x3->b);
	chu(x1,x2,x3);
	printf("x1 / x2 = %.2f%+.2fi\n",x3->a,x3->b);
	return 0;
}
void jia(LinkList x1,LinkList x2,LinkList x3){
	x3->a=x1->a+x2->a;
	x3->b=x1->b+x2->b;
}
	
void jian(LinkList x1,LinkList x2,LinkList x3){
	x3->a=x1->a-x2->a;
	x3->b=x1->b-x2->b; 
}
void cheng(LinkList x1,LinkList x2,LinkList x3){
	x3->a=(x1->a)*(x2->a)-(x1->b)*(x2->b);
	x3->b=(x1->b)*(x2->a)+(x1->a)*(x2->b);
}
void chu(LinkList x1,LinkList x2,LinkList x3){
	x3->a=((x1->a)*(x2->a)+(x1->b)*(x2->b))/((x2->a)*(x2->a)+(x2->b)*(x2->b));
	x3->b=((x1->b)*(x2->a)-(x1->a)*(x2->b))/((x2->a)*(x2->a)+(x2->b)*(x2->b));
}
