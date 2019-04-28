#include<stdio.h>


//´ý¸Ä½ø

 
int main()
{
	double number1=0;
	double number2=0;
	char operation=0;
	printf("\nEnter the calculation:");
	scanf("%lf%c%lf",&number1,&operation,&number2);
	/*Code to check the input goes here*/
	switch(operation){
		case '+':printf("\n%lf%c%lf=%lf",number1,operation,number2,number1+number2); break;
		case '-':printf("\n%lf%c%lf=%lf",number1,operation,number2,number1-number2);break;
		case '*':printf("\n%lf%c%lf=%lf",number1,operation,number2,number1*number2);break;
		case '/':printf("\n%lf%c%lf=%lf",number1,operation,number2,number1/number2);break;
		case '%':
			if((long)number2==0){
				printf("\n\n\aDivisiion by zero error!\n");
				}
			else {
				printf("\n%lf%c%lf=%ld",number1,operation,number2,(long)number1%(long)number2);
			}
			break;
		default:printf("\n\n\aIllegal operation!\n");break;
	}
	return 0;
}
