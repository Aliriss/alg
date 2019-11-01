#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; //为简化起见，元素类型定义为整型
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *LinkList;
LinkList createList(LinkList &L, int n,int position);
LinkList removeInHead(LinkList &L, int n);  //delete in head, n number
void print(LinkList L);                //print exit-element in list
int main(){
	LinkList L=NULL;
	
	int n,num=0;
	while(scanf("%d",&n)){
		L=createList(L,n,1);
		num++;
	}
	print(L);
	printf("\n");
	L=removeInHead(L,num);
	return 0;
}
LinkList createList(LinkList &L,int n,int position){
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
		print(L);
		printf("\n");
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
