#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* Inserts();
void Print(struct ListNode *h);
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2);
int main(){
    printf("Please input two number:");
    struct ListNode *l1,*l2;
    struct ListNode *p1,*p2;
    printf("\nThe first number: ");
    l1=Inserts();
    printf("The second number: ");
    l2=Inserts();
    printf("Put:");
    printf("\n   number1: ");
    Print(l1);
    printf("\n   number2: ");
    Print(l2);
    struct ListNode *p3=addTwoNumbers(l1,l2);
    printf("\nPlaus of number1 and number2: ");
    Print(p3);
    return 0;
}
struct ListNode *Inserts(){
	struct ListNode *h=NULL;
    struct ListNode *p;
    int num;
    scanf("%d",&num);
    while(num>0){
        if(!h){
            h=(struct ListNode *)malloc(sizeof(struct ListNode));
            p=h;
            p->next=NULL;
        }else{
            p->next=(struct ListNode *)malloc(sizeof(struct ListNode));
            p=p->next;
			p->next=NULL;
        }
        p->val=num%10;
        num=num/10;
    }
    return h;
}
void Print(struct ListNode *h){
    if(h->next)
        Print(h->next);
    printf("%d",h->val);
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *p1=l1,*p2=l2,*ans=NULL,*p3=ans;
    int x=0,y=0;
    while(1){
        if(x!=0 && p1==NULL && p2!=NULL) x=p2->val+x;
        else if(x!=0 && p2==NULL && p1!=NULL) x=p1->val+x;
        else if(x!=0 && p1==NULL && p2==NULL) ;
        else if(x==0 && p1==NULL && p2==NULL) break;
        else if(x==0 && p1==NULL) {
			if(p3==NULL)
				return p2;
			p3->next=p2;
			break;
		}
        else if(x==0 && p2==NULL) {
			if(p3==NULL)
				return p1;
			p3->next=p1;
			break;
		}
        else x=p1->val+p2->val+x;
        y=x%10;
        x=x/10;
        if(ans==NULL){
            ans=(struct ListNode*)malloc(sizeof(struct ListNode));
            p3=ans;
            p3->next=NULL;
        }else{
            p3->next=(struct ListNode*)malloc(sizeof(struct ListNode));
            p3=p3->next;
            p3->next=NULL;
        }
        p3->val=y;
        if(p1!=NULL) p1=p1->next;
        if(p2!=NULL) p2=p2->next;
    }
    return ans;
}
