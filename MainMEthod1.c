#include<stdio.h>

int RR_ArrivalTime[30],
	RR_BurstTime[30];	
	
int P_ArrivalTime[30],
    P_BurstTime[30],
	P_Priority[30],
	P_Process[30];

int FCFO_ArrivalTime[30],
    FCFO_BurstTime[30];

int Number,Pointer,Total,ArrivalTime[30],BurstTime[30],
	Priority[30],
	Arr[30],
	Arr1,
	TotalTime=0,
	TimeA=0,
	TimeB=0,
	TimeC=0,
	Count=0,
	Point=0,
	a,b=0,c=0,d=0,A,B,J;

int main()
{
	printf("Enetr the Number of Process:\n");
	scanf("%d",&Number);
	for(a=0;a<Number;a++)
	{
		printf("Process P[%d]\nArrival Time ->",a+1);
		scanf("%d",&ArrivalTime[a]);
		printf("Burst Time ->");
		scanf("%d",&BurstTime[a]);
		printf("Priority ->");
		scanf("%d",&Priority[a]);
		TotalTime=TotalTime+BurstTime[a];
	}
	int Pa[Number];char Pb[Number];
	printf("\n\n");
	for(a=0;a<Number;a++)
	{
		if(Priority[a]>=1 && Priority[a]<=5)
		{
			Pa[a]=a;Pb[a]='A';
			RR_ArrivalTime[b]=ArrivalTime[a];
			RR_BurstTime[b]=BurstTime[a];
			b++;
			TimeA=TimeA+BurstTime[a];
		}
		
		else if(Priority[a]>=6 && Priority[a]<=10)
		{
			Pa[a]=a;Pb[a]='B';
			P_ArrivalTime[c]=ArrivalTime[a];
			P_BurstTime[c]=BurstTime[a];
			P_Priority[c]=Priority[a];
			P_Process[c]=c+1;
			c++;
			TimeB=TimeB+BurstTime[a];
		}
		
		else if(Priority[a]>=11 && Priority[a]<=15)
		{
			Pa[a]=a;Pb[a]='C';
			FCFO_ArrivalTime[d]=ArrivalTime[a];
			FCFO_BurstTime[d]=BurstTime[a];
			d++;
			TimeC=TimeC+BurstTime[a];
		}
	}
	printf("Queue A contains process: ");
	for(a=0;a<Number;a++){
		if(Pb[a]=='A'){
		printf("P[%d] ",Pa[a]);}
	}
	printf("\n");
	printf("Queue B contains process: ");
	for(a=0;a<Number;a++){
		if(Pb[a]=='B'){
		printf("P[%d] ",Pa[a]);}
	}
	printf("\n");
	printf("Queue C contains process: ");
	for(a=0;a<Number;a++){
		if(Pb[a]=='C'){
		printf("P[%d] ",Pa[a]);}
	}
	printf("\n");
	printf("\n");
	
	
	for(a=1;a<TotalTime;a=a+10)
	{
		if(TimeA>10)
		{
			printf("Queue A upto 10\n");
			TimeA=TimeA-10;
		}
		else if(TimeA<=10&&TimeA!=0)
		{
			printf("Queue A upto %d\n",TimeA);
			TimeA=0;
		}
		if(TimeB>10)
		{
			printf("Queue B upto 10\n");
			TimeB=TimeB-10;
		}
		else if(TimeB<=10&&TimeB!=0)
		{
			printf("Queue B upto %d\n",TimeB);
			TimeB=0;
		}
		if(TimeC>10)
		{
			printf("Queue C upto 10\n");
			TimeC=TimeC-10;
		}
		else if(TimeC<=10&&TimeC!=0)
		{
			printf("Queue C upto %d\n",TimeC);
			TimeC=0;
		}
	}
	return 0;
}
