#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

int main(){
	Stack S;   //S is not a pointer
	int i=0;  //e is operation element, i is the number of element in stack;
	initStack(S);
	printf("Please enter the elements in stack(end with '.'): ");
	SElemType e;
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
	//if(isEmptyStack(S)) printf("\nThe Stack is empty!");
	//else printf("\nThe Stack is not empty!");
	
	//the length of stack
	//printf("\nThe length of Stack is: %d",lengthStack(S));

	//get the top of stack
	
	//getTop(S,e);
	//printf("\nThe top element is: %d",e);
	return 0;
}
