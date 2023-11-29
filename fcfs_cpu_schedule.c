#include<stdio.h>

//create structure for processes
struct process{
    int pid;
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};



int main(){
    int n;
    printf("Enter no of process :");
    scanf("%d",&n);
    struct process proc[n],temp;
    int i,j;
    
    //input process info
    for(i=0;i<n;i++){
        printf("Enter ProcessID, ArrivalTime, BurstTime of SNo %d : ",i+1);
        scanf("%d %d %d",&proc[i].pid,&proc[i].at,&proc[i].bt);
    }
    
    //sorting arrival ArrivalTime
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(proc[i].at>proc[j].at){
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    
    // calcualte ct tat wt
    int ctsum = 0 ;
    float avgtat =0 , avgwt = 0;
    for(i=0;i<n;i++){
        ctsum += proc[i].bt;
        proc[i].ct = ctsum;
        
        // calculate TAT
        
        proc[i].tat = proc[i].ct - proc[i].at;
        avgtat += proc[i].tat;
        // calculate wt
        
        proc[i].wt = proc[i].tat - proc[i].bt;
        avgwt += proc[i].wt;
    }
    
    // print the output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].at,proc[i].bt,proc[i].ct,proc[i].tat,proc[i].wt);
        
    }
    
    //calculate and print averate tat and wt
    avgtat = avgtat/n;
    avgwt = avgwt/n;
    printf("Average TurnAroundTime = %f",avgtat);
    printf("Average WaitingTime = %f",avgwt);
    
}
