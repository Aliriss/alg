#include<stdio.h>
#include<stdlib.h>

#define	N	8
typedef struct coordinate {
	int row;
	int col;
} Coord;
typedef struct route {
	int ord;      //sequence number, or order
	Coord coord;   //coordinate of each route
	int direction;  //Direction: down, right, up, left: 1,2,3,4
} Route;
typedef Route ElemType;
typedef struct stack {
	ElemType *base;
	ElemType * top;
	int amount;
} Stack;
//void initMaze(char **maze, int n);
void initStack(Stack &S);
void push(Stack &S,ElemType e);
ElemType pop(Stack &S);
bool isEmptyStack(Stack &S);
int main() {
	//Init maze         0   2   4   6   8
	int maze[10][10]= { 0,0,0,0,0,0,0,0,0,0,           //0
	                    0,1,1,0,1,1,1,0,1,0,
	                    0,1,1,0,1,1,1,0,1,0,           //2
	                    0,1,1,1,1,0,0,1,1,0,
	                    0,1,0,0,0,1,1,1,1,0,           //4
	                    0,1,1,1,0,1,1,1,1,0,
	                    0,1,0,1,1,1,0,1,1,0,           //6
	                    0,1,0,0,0,1,0,0,1,0,
	                    0,0,1,1,1,1,1,1,1,0,           //8
	                    0,0,0,0,0,0,0,0,0,0
	                  };

	//Print maze
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	//Direction: down, right, up, left: 1,2,3,4
	//explore maze
	Stack S;
	initStack(S);
	Coord start,end;   //start coord and end coord
	start.row=1;
	start.col=1;
	end.row=8;
	end.col=8;
	printf("\n(%d,%d)---(%d,%d)",start.row,start.col,end.row,end.col);
	int num=1;           //order of route
	int i=start.row;
	int j=start.col;
	while(i<10&&j<10) {
		if(maze[i][j]==1) {
			Route ro;          ////each route
			ro.coord.row=i;
			ro.coord.col=j;
			ro.ord=num++;
			ro.direction=1;   //prepare for moving down
			push(S,ro);       //Route into stack
			maze[i][j]=2;
			//printf("\n(%d,%d): walked.",ro.coord.row,ro.coord.col);
			if(i==end.row&&j==end.col) {
				printf("\nCongratulation!!!");
				break;
			}
			i++;
		} else if(maze[i][j]==0) {
			while(1) {
				Route quit=pop(S);
				num--;            //route decrease
				i=quit.coord.row;
				j=quit.coord.col;
				++quit.direction;
				push(S,quit);
				num++;
				//printf("\nBack to (%d,%d). And perpare to %d",quit.coord.row,quit.coord.col,quit.direction);
				if(quit.direction==2) {j++;	break;}
				else if(quit.direction==3) {i--;break;}
				else if(quit.direction==4) {j--;break;}
				else  {
					maze[i][j]=2;     //Have access.
					if(isEmptyStack(S)) {
						printf("\nIt is not access.");
						system("pause");
						return 0;
					}
					quit=pop(S);
					num--;
					system("pause");
				}
			}
		} else if(maze[i][j]==2) {
			Route quit=pop(S);    //Delete the No-access
			quit=pop(S);          //last route
			num--;num--;
			i=quit.coord.row;
			j=quit.coord.col;
			++quit.direction;
			push(S,quit);
			num++;
			//printf("\nBack to (%d,%d). And perpare to %d",quit.coord.row,quit.coord.col,quit.direction);
			if(quit.direction==2) j++;
			else if(quit.direction==3) i--;
			else if(quit.direction==4) j--;
		}
	}
	printf("\n-------Route-------\n");
	Stack S2;
	initStack(S2);
	while(!isEmptyStack(S)){
		push(S2,pop(S));
	}
	while(!isEmptyStack(S2)) {
		Route ro=pop(S2);
		printf("(%d,%d)",ro.coord.row,ro.coord.col);
	}

	return 0;
}
void initStack(Stack &S) {
	S.base=(Route*)malloc(N*N*sizeof(Route));
	S.top=S.base;
	S.amount=N*N;
}
void push(Stack &S,ElemType e) {
	*(S.top++)=e;
}
ElemType pop(Stack &S) {
	return *(--S.top);
}
bool isEmptyStack(Stack &S) {
	if(S.top==S.base) return true;
	else return false;
}
