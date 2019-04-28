#include<stdio.h>
#include<stdlib.h>

struct Student
{
	char cName[20];							/*姓名*/
	int iNumber;							/*学号*/
	struct Student* pNext;					/*指向下一个结点的指针*/
};

int iCount;			/*全局变量表示链表长度*/

struct Student* Create()
{
	struct Student* pHead=NULL;	/*初始化链表头指针为空*/
	struct Student* pEnd,*pNew;
	iCount=0;		/*初始化链表长度*/
	pEnd=pNew=(struct Student*)malloc(sizeof(struct Student));
	printf("please first enter Name ,then Number\n");
	scanf("%s",&pNew->cName);
	scanf("%d",&pNew->iNumber);
	while(pNew->iNumber!=0)
	{
		iCount++;
		if(iCount==1)
		{
			pNew->pNext=pHead;			/*使得指向为空*/
			pEnd=pNew;					/*跟踪新加入的结点*/
			pHead=pNew;					/*头指针指向首结点*/
		}
		else
		{
			pNew->pNext=NULL;		/*新结点的指针为空*/
			pEnd->pNext=pNew;		/*原来的为节点指向新结点*/
			pEnd=pNew;				/*pEnd指向新结点*/
		}
		pNew=(struct Student*)malloc(sizeof(struct Student));	/*再次分配结点内存空间*/
		scanf("%s",&pNew->cName);
		scanf("%d",&pNew->iNumber);
	}
	free(pNew);		/*释放没有用到的空间*/
	return pHead;
}

void Print(struct Student* pHead)
{
	struct Student *pTemp;	/*循环所用的临时指针*/
	int iIndex=1;			/*表示链表中结点的序号*/

	printf("----the List has %d members:----\n",iCount);		/*消息提示*/
	printf("\n");		/*换行*/
	pTemp=pHead;			/*指针得到首结点的地址*/

	while(pTemp!=NULL)
	{
		printf("the NO%d member is:\n",iIndex);
		printf("the name is: %s\n",pTemp->cName);	/*输出姓名*/
		printf("the number is: %d\n",pTemp->iNumber);	/*输出学号*/
		printf("\n");	/*输出换行*/
		pTemp=pTemp->pNext;			/*移动临时指针到下一个结点*/
		iIndex++;									/*进行自加运算*/
	}
}


int main()
{
	struct Student* pHead;		/*定义头结点*/
	pHead=Create();				/*创建结点*/
	Print(pHead);				/*输出链表*/
	return 0;					/*程序结束*/
}
