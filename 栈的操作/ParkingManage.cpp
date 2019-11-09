#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 2    //Parking lot has max car.

typedef struct CAR{  //the structure of car
	int num;        // car's number
	int time;       // arrive time or leave time, that means operation time.
}Car;
typedef Car ElemType;
typedef struct Que{    //Street as a queue
	Car car;           
	struct Que *next;
}*QUE;

typedef struct stack{   // Parking lot as a stack.
	ElemType *base;
	ElemType *top;
	int amount;
}Stack;

void initStack(Stack &S); // Init stack, allocate memory.
void push(Stack &S,ElemType e);  //Put the element into the top in stack.
ElemType pop(Stack &S);     //Remove the top element and return.
bool isEmptyStack(Stack &S);  //If stack is empty, return true. Else return false.
bool isFullStack(Stack S);    
void insertQue(QUE &street,ElemType car);  //Car into street.
ElemType outQue(QUE &street);       //Car at the 1 place leaves from street.
bool inStack(Stack S,int num);      // Car in parking lot.
void remove(QUE &street,Car car);   //Car leaves from street.
bool isEmptyQue(QUE street);

int main(){
	Stack S,S2;   // S is first, S2 is departure
	initStack(S);  //Init stack, allocate memory.
	initStack(S2);
	char ch;       //A: arrival; D: departure; E: end
	Car arrivalCar,departureCar;   
	QUE street=NULL;
	if(street==NULL) printf("Street has no car.\n");
	int i=0,j=0;
	int flag;
	while(1){
		scanf("%c%d%d",&ch,&(arrivalCar.num),&(arrivalCar.time));
		if(ch=='A') {
			if(!isFullStack(S) && isEmptyQue(street)){
				push(S,arrivalCar);
				j++;
				printf("\nNo%d in the parking lot(position: %d), Arrival time: %d.\n",arrivalCar.num,j,arrivalCar.time);
			}else{
				insertQue(street,arrivalCar);
				flag=1;
				i++;
			}
		}
		else if(ch=='D'){
			//printf("\narrivalcar: %d",arrivalCar.num);
			if( inStack(S,arrivalCar.num) ){  //if car in stack, the car behind him left the station to let him leave.
				departureCar=pop(S);
				while(departureCar.num!=arrivalCar.num){  //find the car want to leave.
					push(S2,departureCar);
					departureCar=pop(S);
				}
				printf("\nNo%d car has left.",departureCar.num);
				printf("\n\tStay %d time, need pay $%.2f\n",arrivalCar.time-departureCar.time,1.0*(arrivalCar.time-departureCar.time));
				j--;
				if(!isEmptyStack(S2)) push(S,pop(S2));   //The car helped that car into paarking lot.(just ont car).
				flag=0;
			}else{
				//printf("dsjlafkjl");
				remove(street,arrivalCar);
				flag=0;
			}
		}
		else if(ch=='E') break;
		if(!isFullStack(S) && !isEmptyQue(street)) {
			departureCar=outQue(street);
			push(S,departureCar);
			i--;j++;
			//printf("\nNo%d drive from street to parking lot(position: %d).\n",departureCar.num,j);
		}else if(flag==1){
			printf("\nNo%d parking in the street(position: %d), Arrival time: %d.\n",arrivalCar.num,i,arrivalCar.time);
		}
		//fflush(stdin);
		getchar();
	}
	
//('A',1,5),('A',2,10),('D',1,15),('A',3,20),('A',4,25),('A',5,30),('D',2,35),('D',4,40),('E',0,0)
//A 1 5 A 2 10 D 1 15 A 3 20 A 4 25 A 5 30 D 2 35 D 4 40 E 0 0
	return 0;
}
// Init stack, allocate memory.
void initStack(Stack &S){
	S.base=(ElemType*)malloc(MAXSIZE*sizeof(ElemType));
	S.top=S.base;
	S.amount=MAXSIZE;
}


void insertQue(QUE &street,ElemType car){
	QUE streetP=street;
	if(street==NULL) {
		street=(QUE)malloc(sizeof(struct Que));
		street->next=NULL;
		streetP=street;
	}else{
		while(streetP->next!=NULL){
			streetP=streetP->next;
		}
		streetP->next=(QUE)malloc(sizeof(struct Que));
		streetP=streetP->next;
		streetP->next=NULL;
	}
	streetP->car=car;
}

ElemType outQue(QUE &street){
	//if(street==NULL) printf("\nque is NULL");
	QUE streetP=street;
	Car car;
	if(street!=NULL){
		car.num=streetP->car.num;
		car.time=streetP->car.time;
		street=street->next;
		free(streetP);
		return car;
	}else{
		printf("No car in que.");
	}
}
void push(Stack &S,ElemType e){
	if( ((S.top)-(S.base)) < S.amount ) {
		*(S.top++)=e;
	}else{
		printf("\nYour Stack is full!");
		system("pause");
	}
}
ElemType pop(Stack &S){
	Car c;
	c.num=0,c.time=0;
	if(S.top>S.base){
		return *(--S.top);
	}else{
		printf("The stack is empty!");
		return c;
	}
}
void remove(QUE &street,Car car){
	QUE p=street,prep=street;
	while(p->next!=NULL){
		if(p->car.num==car.num&&p==street){
			if(p==street) {
				street=street->next;
				printf("\nNo%d leave from street.",p->car.num);
				break;
			}else{
				prep->next=p->next;
				printf("\nNo%d leave from street.",p->car.num);
				break;
			}
		}
		prep=p;
		p=p->next;
		system("pause");
	}
}
bool inStack(Stack S,int num){
//	printf("\n you in in stack.");
	Car *p=S.base;
	int i=2;
	while(i>0){
		if(p->num==num) {
			return true;
		}
		p++;
		i--;
	}
	return false;
}
bool isEmptyStack(Stack &S){
	if(S.base==S.top) return true;
	else return false;
}
bool isFullStack(Stack S){
	if((S.top-S.base)==MAXSIZE) {
		//printf("\nParking lot has %d car.",S.amount);
		return true;
	}
	else {
		//printf("\nParking lot has %d car.",S.top-S.base);
		return false;
	}
}
bool isEmptyQue(QUE street){
	if(street!=NULL) return false;
	else return true;
}

