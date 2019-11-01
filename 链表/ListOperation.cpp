#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; //为简化起见，元素类型定义为整型
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *LinkList;
LinkList insertList(LinkList &L,int position,int n);
LinkList removeInHead(LinkList &L, int n);  //delete in head, n number
LinkList removeInPosition(LinkList &L, int n);  //delete n position
void print(LinkList L);                //print exit-element in list
int main(){
	LinkList L=NULL;
	//Init:
	printf("Please input a list of number and end of '.': \n");
	int n;
	while(scanf("%d",&n)){
		L=insertList(L,1,n);
	}
	fflush(stdin);
	printf("You get a list: ");
	print(L);
	printf("\nPlease input a number you want insert into list: ");
	scanf("%d",&n);
	printf("Please input the position you want insert: ");
	int position;
	scanf("%d",&position);
	L=insertList(L,position,n);
	printf("You get a list: ");
	print(L);
	
	printf("\nPlease input the position you want delete: ");
	scanf("%d",&position);
	L=removeInPosition(L,position);
	printf("You get a list: ");
	print(L);
	printf("\nHow many numbers you want to deleat: ");
	scanf("%d",&n);
	L=removeInHead(L,n);
	print(L);
	return 0;
}
LinkList insertList(LinkList &L,int position,int n){
	LinkList p,q;
	if(L==NULL){
		L = (LinkList) malloc(sizeof(Node));
		L->next=NULL;
	}
	p=L;
	while(position && p!=NULL){
		if(position==1){
			q=(LinkList)malloc(sizeof(Node));
			q->data=n;
			q->next=p->next;
			p->next=q;
			return L;
		}
		p=p->next;
		position--;
	}
	getchar();
	printf("error!!!");
	return L;
}

LinkList removeInHead(LinkList &L, int n){ //用表头插入法逆序建立长度为n 的、带头结点的单链表
	LinkList p=L;
	for(n; n>0 && L->next!=NULL; --n) {
		p=L->next;
		L->next=p->next;
		free(p);
	}
	return L;
}
LinkList removeInPosition(LinkList &L, int n){
	LinkList p=L,q=NULL;
	while(p!=NULL){
		if(n==1){
			q=p->next;
			p->next=q->next;
			free(q);
			return L;
		}
		n--;
		p=p->next;
	}
	return L;
}
void print(LinkList L){
	LinkList p=L->next;
	if(p==NULL) printf("Empty list!");
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
