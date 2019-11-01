#include<stdio.h>
#include<stdlib.h>


#define STACK_INIT_SIZE 100     
#define STACKINCREMENT 10
#define SElemType int


typedef struct {
	SElemType *base;
	SElemType *top;  
	int stackSize;
}SqStack;
// create a empty stack
bool initStack(SqStack &S);
//destory a stack
bool destroyStack(SqStack &S);
//set a stack is an empty stack
bool clearStack(SqStack &S);
//is empty stack?
bool emptyStack(SqStack &S);
//
int lengthStack(SqStack &S);
bool getTop(SqStack S,SElemType &e);
bool push(SqStack &S, SElemType e);
bool pop(SqStack &S,SElemType &e);
//bool StackTraverse(SqStack S, Status( (*visit)()));
int main(){
	SqStack S;   //S is not a pointer
	int e,i=0;  //e is operation element, i is the number of element in stack;
	initStack(S);
	//insert element into stack
	while((scanf("%d",&e))) {
		getchar();
		push(S,e);
		i++;
	}
	
//	for(i;i>0;i--){
//		pop(S,e);
//		printf("%d",e);
//	}
	//clearStack(S);
	if(emptyStack(S)) printf("\nThe Stack is empty!");
	else printf("\nThe Stack is not empty!");
	
	//the length of stack
//	printf("\nThe length of Stack is: %d",lengthStack(S));

	//get the top of stack
//	getTop(S,e);
//	printf("\nThe top element is: %d",e);
	return 0;
}
//an empty stack
bool initStack(SqStack &S){
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return false;
	S.top=S.base;
	S.stackSize=STACK_INIT_SIZE;
	return true;
}
//get the top elemnt in stack 
bool getTop(SqStack S,SElemType &e){
	if(S.top==S.base) return false;
	e=*(S.top-1);
	return true;
}
//insert an element into stack
bool push(SqStack &S, SElemType e){
	if(S.top-S.base >= S.stackSize) {
		S.base=(SElemType *)realloc(S.base,(S.stackSize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return false;
		S.top=S.base+S.stackSize;
		S.stackSize+=STACKINCREMENT;
	}
	*S.top++=e;
	return true;
}
//release an element 
bool pop(SqStack &S,SElemType &e){
	if(S.top==S.base) return false;
	e=*--S.top;
	return true;
}
//the length of stack
int lengthStack(SqStack &S){
	return S.top-S.base;
}
//destory a stack
bool destroyStack(SqStack &S){
	free(&S);
}
//set a stack is an empty stack
bool clearStack(SqStack &S){
	SElemType e;
	while(S.top!=S.base){
		pop(S,e);
	}
	return true;
}
//is empty stack?
bool emptyStack(SqStack &S){
	if(S.top==S.base) return true;
	return false;
}
