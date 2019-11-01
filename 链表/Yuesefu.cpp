#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; //为简化起见，元素类型定义为整型
typedef struct Node{
	ElemType order;
	ElemType m;
	struct Node *next;
}Node, *LinkList;
LinkList CreateList_L2(LinkList L, int n,int position);
void print(LinkList L);                //print exit-element in list
LinkList play(LinkList L,int m);
int main(){
	LinkList L=NULL;
	
	printf("Please input a list of number and end of '.': ");
	int n,i=1;
	while((scanf("%d",&n))){
		getchar();
		L=CreateList_L2(L,n,i++);
	}
	printf("You get a list: ");
	print(L);
	LinkList p=L;
	while(p->next!=NULL){
		p=p->next;
	}
	p->next=L;
	
	printf("\nPlease input the m: ");
	int m;
	getchar();
	scanf("%d",&m);
	L=play(L,m);
	return 0;
}

LinkList CreateList_L2(LinkList L,int n,int position){
	LinkList p=L;
	int x=position;
	while(position){
		if(L==NULL){
			L=(LinkList)malloc(sizeof(Node));
			L->next=NULL;
			p=L;
		}else if(p->next!=NULL){
			p=p->next;
			continue;
		}else{
			p->next=(LinkList)malloc(sizeof(Node));
			p=p->next;
			p->next=NULL;
		}
		p->m=n;
		p->order=position;
		break;
	}
	return L;
}
LinkList play(LinkList L,int m){
	int i;
	LinkList prep=L,p=L,q;
	while(p->next!=L){
		p=p->next;
	}
	prep=p;p=L;
	for(i=1;i<=m;i++){
		if(i==m){
			prep->next=p->next;
			printf("%d ",p->order);
			m=p->m;
			prep=p;
			free(p);
			p=prep->next;
			i=0;
		}else{
			prep=p;
			p=p->next;
		}
		if((prep->order)==(p->order)){
			break;
		}
	}
	return prep;
}
void print(LinkList L){
	LinkList p=L;
	if(p==NULL) printf("Empty list!");
	while(p!=NULL){
		printf("\n%d: %d ",p->order,p->m);
		p=p->next;
	}
}
