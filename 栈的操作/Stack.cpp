#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;  // Define the type of the element in Struct.

typedef struct stack{   // It is a Stack.
	ElemType *base;
	ElemType *top;
	ElemType amount;
}Stack;

void initStack(Stack &S); // Init stack, allocate memory.
void push(Stack &S,ElemType e);  //Put the element into the top in stack.
ElemType pop(Stack &S);     //Remove the top element and return.
bool isEmptyStack(Stack &S);  //If stack is empty, return true. Else return false.

int main(){
	Stack S;   // Define a Stack.
	initStack(S);  //Init stack, allocate memory.
	printf("Transform: Int -> Binary System.\nEnter the number: ");
	int num;
	scanf("%d",&num);
	int Quo=num,Rem=0;  //Define the Quotient and remainder
	if(num==0) printf("%d: %d ",num,0);
	while(Quo!=0){
		Rem=Quo%2;
		push(S,Rem);
		Quo=Quo/2;
	}
	printf("%d: ",num);
	while(!isEmptyStack(S)){
		printf("%d ",pop(S));
	}
	return 0;
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
bool isEmptyStack(Stack &S){
	if(S.base==S.top) return true;
	else return false;
}

