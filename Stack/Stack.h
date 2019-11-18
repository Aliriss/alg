
#include<stdlib.h>

#define STACK_INIT_SIZE 100     
#define STACKINCREMENT 10
#define SElemType int


typedef struct {
	SElemType *base;
	SElemType *top;  
	int stackSize;
}Stack;
//bool StackTraverse(SqStack S, Status( (*visit)()));

//Init an empty stack
bool initStack(Stack &S){
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base) return false;
	S.top=S.base;
	S.stackSize=STACK_INIT_SIZE;
	return true;
}
//get the top elemnt in stack 
bool getTop(Stack S,SElemType &e){
	if(S.top==S.base) return false;
	e=*(S.top-1);
	return true;
}
//insert an element into stack
bool push(Stack &S, SElemType e){
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
bool pop(Stack &S,SElemType &e){
	if(S.top==S.base) return false;
	e=*--S.top;
	return true;
}
//the length of stack
int lengthStack(Stack &S){
	return S.top-S.base;
}
//destory a stack
bool destroyStack(Stack &S){
	free(&S);
}
//set a stack is an empty stack
bool clearStack(Stack &S){
	SElemType e;
	while(S.top!=S.base){
		pop(S,e);
	}
	return true;
}
//is empty stack?
bool isEmptyStack(Stack &S){
	if(S.top==S.base) return true;
	return false;
}
