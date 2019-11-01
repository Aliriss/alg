#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; //Ϊ�������Ԫ�����Ͷ���Ϊ����
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

LinkList removeInHead(LinkList &L, int n){ //�ñ�ͷ���뷨����������Ϊn �ġ���ͷ���ĵ�����
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
