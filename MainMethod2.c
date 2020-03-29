#include<stdio.h>

int RR_ArrivalTime[30],
	RR_BurstTime[30];
float RR_AverageWaitingTime=0.0,
      RR_AverageTurnAroundTime=0.0;	
	
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
  RoundRobinMethodScheduling();
	return 0;
}

//Queue A(higher range of priority)
void RoundRobinMethodScheduling()
{
	for(a=0;a<b;a++)
	{
		Arr[a]=RR_BurstTime[a];
	} 
	
	//calculating burst,waiting and turnaround time taking by each process
	printf("|Process ID|Burst Time|Waiting Time|Turnaround Time|(RR scheduling[quantum time=4])\n");
	J=b;
    for(a=0,Total=0;J!=0;) 
    { 
    	if(Arr[a]<=4&&Arr[a]>0) 
        {   printf(" P[%d](%d) |",a+1,Arr[a]);
            Total=Total+Arr[a]; 
            Arr[a]=0; 
            Count=1; 
        } 
        else if(Arr[a]>0) 
        {
		    printf(" P[%d](4) |",a+1);	
            Arr[a]=Arr[a]-4; 
            Total=Total+4;
        } 
        if(Arr[a]==0&&Count==1) 
        { 
            J--; 
            printf("\n   P[%d]\t\t    %d\t\t %d\t\t %d\n",a+1,RR_BurstTime[a],Total-RR_ArrivalTime[a]-RR_BurstTime[a],Total-RR_ArrivalTime[a]);
            RR_AverageWaitingTime=RR_AverageWaitingTime+Total-RR_ArrivalTime[a]-RR_BurstTime[a]; 
            RR_AverageTurnAroundTime=RR_AverageTurnAroundTime+Total-RR_ArrivalTime[a]; 
            Count = 0; 
        } 
        if(a==b-1) 
        {
            a=0; 
        }
        else if(RR_ArrivalTime[a+1]<=Total) 
        {
            a++;
        }

        else 
        {
            a=0;
        }
    }
    printf("\nAverage Waiting Time of Round Robin Scheduling is   :%f",RR_AverageWaitingTime/b); 
    printf("\nAverage Turnaround Time of Round Robin Scheduling is:%f\n\n",RR_AverageTurnAroundTime/b); 
}
//Queue B(Medium range of priority)
void PriorityScheduling()
{
	
	//calculating the burst time
	for(a=0;a<c;a++)
    {
        Pointer=a;
        for(A=a+1;A<c;A++)
        {
            if(P_Priority[A]<P_Priority[Pointer])
            {
                Pointer=A;
            }
        }
        Arr1=P_Priority[a];
        P_Priority[a]=P_Priority[Pointer];
        P_Priority[Pointer]=Arr1; 
        
        Arr1=P_BurstTime[a];
        P_BurstTime[a]=P_BurstTime[Pointer];
        P_BurstTime[Pointer]=Arr1;
        
        Arr1=P_Process[a];
        P_Process[a]=P_Process[Pointer];
        P_Process[Pointer]=Arr1;
    }
    P_WaitingTime[0]=0;
	
	//calculating the waiting time
    for(a=1;a<c;a++)
    {
        P_WaitingTime[a]=0;
        for(A=0;A<a;A++)
        {
            P_WaitingTime[a]=P_WaitingTime[a]+P_BurstTime[b];
        }
        Point=Point+P_WaitingTime[a];
    }
    P_AverageWaitingTime=Point/c;
    Point=0;
    printf("|Process ID|Burst Time|Waiting Time|Turnaround Time|(Periority scheduling)\n");
    for(a=0;a<c;a++)
    {
    	P_TurnAroundTime[a]=P_BurstTime[a]+P_WaitingTime[a];
        Point=Point+P_TurnAroundTime[a];
        printf("\n   P[%d]\t\t   %d\t\t %d\t\t %d\n",P_Process[a],P_BurstTime[a],P_WaitingTime[a],P_TurnAroundTime[a]);
    }
	for(a=0;a<c;a++)
    {
    	while(P_BurstTime[a]!=0)
    	{
    		if(P_BurstTime[a]>10)
    		{
				printf(" P[%d](10) |",a+1);
				P_BurstTime[a]=P_BurstTime[a]-10;
			}
			else if(P_BurstTime[a]<=10)
			{
				printf(" P[%d](%d) |",a+1,P_BurstTime[a]);
				P_BurstTime[a]=0;
			}
		}
	}
	printf("\n");
    P_AverageTurnAroundTime=Point/c;
    printf("\nAverage Waiting Time for Priority  Scheduling is  :\t%f",P_AverageWaitingTime);
    printf("\nAverage Turnaround Time for Priority Scheduling is:\t%f\n\n",P_AverageTurnAroundTime);
}
