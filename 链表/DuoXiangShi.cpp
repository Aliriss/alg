#include<stdio.h>
#include<stdlib.h>
typedef int ElemType; 
typedef struct Node{
	int coe; // The coefficient.
	int exp; //The exponent.
	struct Node *next;
}Node, *LinkList;

void initList(LinkList &L);
void createList(LinkList L);
void createNode(LinkList &p);
//Sort from little to big.
void sort(LinkList L);
// Simplify the same struct(exp same)
void simplify(LinkList L);
LinkList AddTwoD(LinkList x1,LinkList x2);
LinkList JianTwoD(LinkList x1,LinkList x2);
void sort(LinkList L);
void print(LinkList L);
int main(){
	LinkList x1=NULL,x2=NULL,x3=NULL,x4=NULL;
	
	//Input two multinomals.
	printf("The first: ");
	initList(x1);
	createList(x1);
	printf("The second: ");
	initList(x2);
	createList(x2);
	sort(x1);
	simplify(x1);
	printf("\nx1: ");
	print(x1);
	
	sort(x2);
	simplify(x2);
	printf("\nx2: ");
	print(x2);

	//Operation.
	x3=AddTwoD(x1,x2);
	printf("\nX1 + X2 = ");
	print(x3);
	x4=JianTwoD(x1,x2);
	printf("\nX1 - X2 = ");
	print(x4);
	return 0;
}
void initList(LinkList &L){
	L=(LinkList)malloc(sizeof(Node));
	L->next=NULL;
}
void createList(LinkList L){
	LinkList p=L;  
	int coe,exp;
	printf("\nPlease input the coefficient and exponent (exit by input '.'): ");
	while((scanf("%d",&coe))&&(scanf("%d",&exp))){
		createNode(p);
		p->coe=coe;
		p->exp=exp;
		printf("Please input the next coefficient and exponent (exit by input '.'): ");
	}
	fflush(stdin);
}
//p=L->next: p->next=NULL; so we need create as this sample;
//create node and point p to p->next;
void createNode(LinkList &p){
	if(p->next==NULL){
		p->next=(LinkList)malloc(sizeof(Node));
		p->next->next=NULL;
		p=p->next;
		p->coe=0;
		p->exp=0;
	}else{
		system("pause");
	}
}


LinkList AddTwoD(LinkList x1,LinkList x2){
	LinkList p=x1->next,q=x2->next,result=NULL;
	initList(result);
	LinkList pr=result;
	while(p!=NULL&&q!=NULL){
		createNode(pr);
		if((p->exp)==(q->exp)){  //if their has the same exponent, then add their coefficient.
			pr->coe=p->coe+q->coe;
			pr->exp=p->exp;
			p=p->next;
			q=q->next;
		}else if((p->exp)<(q->exp)){   //Comparation is used to sort.
			pr->coe=p->coe;
			pr->exp=p->exp;
			p=p->next;
		}else {   
			pr->coe=q->coe;
			pr->exp=q->exp;
			q=q->next;
		}
	}
	//Plus others.
	if(q==NULL){
		while(p!=NULL){
			createNode(pr);
			pr->coe=p->coe;
			pr->exp=p->exp;
			p=p->next;
		}
	}else if(p==NULL){
		while(q!=NULL){
			createNode(pr);
			pr->coe=q->coe;
			pr->exp=q->exp;
			q=q->next;
		}
	}
	return result;
}
LinkList JianTwoD(LinkList x1,LinkList x2){
	LinkList p=x1->next,q=x2->next,result=NULL;
	initList(result);
	LinkList pr=result;
	while(p!=NULL&&q!=NULL){
		createNode(pr);
		if((p->exp)==(q->exp)){
			pr->coe=(p->coe)-(q->coe);
			pr->exp=p->exp;
			p=p->next;
			q=q->next;
		}else if((p->exp)<(q->exp)){
			pr->coe=p->coe;
			pr->exp=p->exp;
			p=p->next;
		}else {
			pr->coe -= q->coe;
			pr->exp=q->exp;
			q=q->next;
		}
	}
	if(q==NULL){
		while(p!=NULL){
			createNode(pr);
			pr->coe=p->coe;
			pr->exp=p->exp;
			p=p->next;
		}
	}else if(p==NULL){
		while(q!=NULL){
			createNode(pr);
			pr->coe -=q->coe;
			pr->exp=q->exp;
			q=q->next;
		}
	}
	return result;
}
void simplify(LinkList L){
	LinkList p=L->next,q=NULL;
	while(p->next !=NULL){
		q=p;
		while(q->next!=NULL){
			if((p->exp)==(q->next->exp)){
				p->coe+=q->next->coe;
				LinkList f=q->next;
				q->next=q->next->next;
				free(f);
				
			}else q=q->next;
		}
		if(p->next!=NULL)
			p=p->next;
	}
}
void sort(LinkList L){
	LinkList p=L->next,q=NULL;  //loop pointer
	LinkList minPointer=NULL;  //Use to mark the min-data-structure
	Node first;     //Use to become the bridge to change two struct    :=(Node)malloc(sizeof(Node))
	while(p->next !=NULL){
		q=p->next;
		while(q !=NULL){
			if((p->exp) > (q->exp))
				minPointer=q;
			q=q->next;
		}
		if(minPointer!=NULL){  //swap two struct
			first=*minPointer;
			*minPointer=*p;
			minPointer->next=first.next;
			first.next=p->next;
			*p=first;
			minPointer=NULL;
		}
		p=p->next;
	}
}


void print(LinkList L){
	LinkList p=L->next;
	if(p==NULL) printf("Empty list!");
	while(p!=NULL){
		printf("%dx^%d ",p->coe,p->exp);
		p=p->next;
	}
	printf("\n");
}
