#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50

typedef char ElemType;  // Define the type of the element in Struct.

typedef struct stack{   // It is a Stack.
	ElemType *base;
	ElemType *top;
	int amount;
}Stack;
void initStack(Stack &S); // Init stack, allocate memory.
void push(Stack &S,ElemType e);  //Put the element into the top in stack.
ElemType pop(Stack &S);     //Remove the top element and return.
ElemType getTop(Stack &S);  //get the element in stack, don't pop
bool isEmptyStack(Stack &S);  //If stack is empty, return true. Else return false.
bool checkBrackets(ElemType *e);
int main(){
	Stack S;   // Define a Stack.
	initStack(S);  //Init stack, allocate memory.
	printf("Judge: brackets.\nEnter the expression: ");
	char *ch=(char *)malloc(MAXSIZE*sizeof(char));
	gets(ch);
	if(checkBrackets(ch)){
		printf("True.");
	}else printf("False.");
	return 0;
}
bool checkBrackets(ElemType *ch){
	int i;
	Stack S;
	initStack(S);
	for(i=0;ch[i]!='\0';i++){
		if(ch[i]=='(' || ch[i]=='[' ||ch[i]=='{'){
			push(S,ch[i]);
		}else if (ch[i]==')' || ch[i]==']' || ch[i]=='}' ) {
			if(isEmptyStack(S)){
				return false;
			}else{
				switch(getTop(S)){
					case '(': if(')' !=ch[i]) return false;
							else pop(S);break;
					case '[': if(']' !=ch[i]) return false;
							else pop(S);break;
					case '{': if('}' !=ch[i]) return false;
							else pop(S);break;
				}
			}
		}
	}
	return true;
}


// Init stack, allocate memory.
void initStack(Stack &S){
	S.base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
	S.top=S.base;
	S.amount=MAXSIZE;
}
void push(Stack &S,ElemType e){
	if( ((S.top)-(S.base)) < MAXSIZE ) {
		*(S.top++)=e;
	}else{
		printf("\nYour Stack is full!");
		system("pause");
	}
}
ElemType pop(Stack &S){
	if(S.top>S.base){
		return *(--S.top);
	}
}
ElemType getTop(Stack &S){
	return *(S.top-1);
}
bool isEmptyStack(Stack &S){
	if(S.base==S.top) return true;
	else return false;
}

