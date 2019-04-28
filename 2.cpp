//题目：企业发放的奖金根据利润提成。
//利润低于或等于10万元时，奖金可提10%；
//利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
//20万到40万之间时，高于20万元的部分，可提成5%；
//40万到60万之间时,高于40万元的部分，可提成3%；
//60万到100万之间时，高于60万元的部分，可提成1.5%;
//高于100万元时，超过100万元的部分按1%提成;
//从键盘输入当月利润I，求应发放奖金总数？
long long int c(int d)
{
	long long int total=0;
	if(d<=100000)
	{
		return d*(1.0+0.1);
	}else if(d>100000&&d<=200000){
		total+=(d-100000)*(1.0+0.075)+c(d-100000);
	}else if(d>200000&&d<=400000){
		total+=(d-200000)*(1.0+0.05)+c(d-200000);
	}else if(d>400000&&d<=600000){
		total+=(d-400000)*(1.0+0.03)+c(d-400000);
	}else if(d>600000&&d<=1000000){
		total+=(d-600000)*(1.0+0.015)+c(d-600000);
	}else if(d>1000000){
		total+=(d-1000000)*(1.0+0.01)+c(d-1000000);
	}
	return total;
}
#include<stdio.h>
int main()
{
	long long int sallary;
	scanf("%lld",&sallary);
	printf("total is:%lld",c(sallary));
	return 0;
}
/*
main()
{
long int i;
int bonus1,bonus2,bonus4,bonus6,bonus10,bonus;
scanf("%ld",&i);
bonus1=100000*0.1;bonus2=bonus1+100000*0.75;
bonus4=bonus2+200000*0.5;
bonus6=bonus4+200000*0.3;
bonus10=bonus6+400000*0.15;
　if(i<=100000)
　　bonus=i*0.1;
　else if(i<=200000)
　　　　　bonus=bonus1+(i-100000)*0.075;
　　　　else if(i<=400000)
　　　　　　　　bonus=bonus2+(i-200000)*0.05;
　　　　　　　else if(i<=600000)
　　　　　　　　　　　bonus=bonus4+(i-400000)*0.03;
　　　　　　　　　　else if(i<=1000000)
　　　　　　　　　　　　　　bonus=bonus6+(i-600000)*0.015;
　　　　　　　　　　　　　else
　　　　　　　　　　　　　　bonus=bonus10+(i-1000000)*0.01;
printf("bonus=%d",bonus);
}
*/
