#include<stdio.h>
#include<stdlib.h>

typedef int ElemType; //Define element in struct Node.

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *LinkList;
//creat head node;
LinkList initList();
//create list
LinkList createList(LinkList L);
//insert elemet in one position
LinkList insertList(LinkList L, ElemType element, int position);
//sort from little to big.
LinkList sortInStruct(LinkList L);
LinkList sortInData(LinkList L);
//print all element in list
void print(LinkList L);
int main(){
	LinkList L=initList();
	L=createList(L);
	printf("You get a list: ");
	print(L);
	L=sortInStruct(L);
	printf("\nSort: ");
	print(L);
	return 0;
}

LinkList initList(){
	LinkList p=(LinkList)malloc(sizeof(Node));
	p->next=NULL;
	return p;
}
LinkList insertList(LinkList L, ElemType element, int position){
	// Insert the element into the position at list-L;
	LinkList p=L,q=NULL;
	while(position && p!=NULL){  //position >0 and position is not over broad
		if(position==1){    // Find the position we will to insert.
			q=(LinkList)malloc(sizeof(Node));
			q->data=element;
			q->next=p->next;
			p->next=q;
			return L;
		}
		p=p->next;
		position--;
	}
	printf("Don\'t have this position!!!");
	return L;
}
LinkList createList(LinkList L){
	printf("Please input a list of number and end of '.': ");
	int n,i=1;
	while((scanf("%d",&n))){   // If scan failly, return 0, else return the amount of the successful scan
		getchar();
		L=insertList(L,n,i++);
	}
	return L;
}
void print(LinkList L){   
	LinkList p=L->next;
	if(p==NULL) printf("Empty list!"); // It is a empty list 
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
LinkList sortInData(LinkList L){
	LinkList p,q;
	LinkList x;
	for(p=L->next;p->next!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if((p->data)>(q->data)){
				int change=q->data;
				q->data=p->data;
				p->data=change;
			}
		}
	}
	return L;
}
LinkList sortInStruct(LinkList L){
	LinkList p=L->next,q=NULL;  //loop pointer
	LinkList minPointer=NULL;  //Use to mark the min-data-structure
	LinkList first=(LinkList)malloc(sizeof(Node));     //Use to become the bridge to change two struct
	while(p->next !=NULL){
		q=p->next;
		while(q !=NULL){
			if((p->data) > (q->data)){
				minPointer=q; 
			}
			q=q->next;
		}
		if(minPointer!=NULL){
			*first=*minPointer;
			*minPointer=*p;
			minPointer->next=first->next;
			first->next=p->next;
			*p=*first;
			minPointer=NULL;
		}
		p=p->next;
	}
	return L;
}

/*   Not accomplish
LinkList sortInPointer(LinkList list){
	LinkList prep=NULL,preq=NULL,p=NULL,q=NULL;
	for(prep=L,p=prep->next;p->next!=NULL;prep=p,p=p->next) {
		for(preq=p,q=preq->next;q!=NULL;preq=q,q=q->next) {
			if( (p->data) > (q->data) ) {
				if( p == preq ) {
					prep->next=q;
					p->next=q->next;
					q->next=p;
				}else if( p->next == preq) {
					prep->next=q;
					preq->next=p;
					p->next=q->next;
					q->next=preq;
				}else {
					prep->next=p->next;
					preq->next=q->next;
					p->next=q->next;
					preq->next=p;
					q->next=prep->next;
					prep->next=q;
				}
			}
			p=prep->next;
			q=preq->next;
		}
	}
	return L;
}*/
