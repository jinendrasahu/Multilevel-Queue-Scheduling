#include<stdio.h>

int RR_ArrivalTime[30],
	RR_BurstTime[30];	
	
int P_ArrivalTime[30],
    P_BurstTime[30],
	P_Priority[30],
	P_Process[30];

//Queue C
int FCFO_ArrivalTime[30],
    FCFO_BurstTime[30],
    FCFO_WaitingTime[30],
    FCFO_TurnAroundTime[30];
	
float FCFO_AverageWaitingTime=0.0,
      FCFO_AverageTurnAroundTime=0.0;

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
  FirstComeFirstOutScheduling();
	return 0;
}
//Queue C(Lower range of priority)
void FirstComeFirstOutScheduling()
{
	FCFO_WaitingTime[0] = 0;
    
//calculating waiting time	
    for(a=1;a<d;a++)
    {
        FCFO_WaitingTime[a] = 0;
        for(B=0;B<d;B++)
        {
            FCFO_WaitingTime[a]=FCFO_WaitingTime[a]+FCFO_BurstTime[B];
        }
    }
	//calculating burst,waiting,turnaround time	
    printf("|Process ID|Burst Time|Waiting Time|Turnaround Time|(FCFO scheduling)\n");
    for(a=0;a<d;a++)
    {
        FCFO_TurnAroundTime[a]=FCFO_BurstTime[a]+FCFO_WaitingTime[a];
        FCFO_AverageWaitingTime=FCFO_AverageWaitingTime+FCFO_WaitingTime[a];
        FCFO_AverageTurnAroundTime=FCFO_AverageTurnAroundTime+FCFO_TurnAroundTime[a];
        printf("\n   P[%d]\t\t %d\t %d\t\t %d\n",a+1,FCFO_BurstTime[a],FCFO_WaitingTime[a],FCFO_TurnAroundTime[a]);
    }
	for(a=0;a<d;a++)
    {
    	while(FCFO_BurstTime[a]!=0)
    	{
    		if(FCFO_BurstTime[a]>10)
    		{
				printf(" P[%d](10) |",a+1);
				FCFO_BurstTime[a]=FCFO_BurstTime[a]-10;
			}
			else if(FCFO_BurstTime[a]<=10)
			{
				printf(" P[%d](%d) |",a+1,FCFO_BurstTime[a]);
				FCFO_BurstTime[a]=0;
			}
		}
	}
    printf("\n\nAverage Waiting Time for FCFO sheduling is   :%f",FCFO_AverageWaitingTime/d);
    printf("\nAverage Turnaround Time for FCFO sheduling is:%f\n",FCFO_AverageTurnAroundTime/d);
}

