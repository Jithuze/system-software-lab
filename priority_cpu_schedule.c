

#include <stdio.h>

struct process {
  int pid;
  int bt;
  int tat;
  int wt;
  int pt;
};

int main()
{
    int i,j,n;
    
    printf("Enter the no of processes : ");
    scanf("%d",&n);
    
    struct process proc[n],temp;
    
    for(i=0;i<n;i++){
        printf("Enter BT of processes %d :",i+1);
        scanf("%d",&proc[i].bt);
        printf("Enter Priority : ");
        scanf("%d",&proc[i].pt);
        proc[i].pid = i+1;
    }
    
    //Sort priority time
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(proc[i].pt>proc[j].pt){
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
    
    proc[0].wt = 0;
    float wtSum = 0;
    
    for(i=1;i<n;i++){
        proc[i].wt = proc[i-1].wt + proc[i-1].bt;
        wtSum = wtSum + proc[i].wt;
        
    }
    
    for(i=0;i<n;i++){
        proc[i].tat = proc[i].bt + proc[i].wt;
    }
    
    
    
    printf("PID\tBT\tPT\tTAT\tWT\t");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d\t%d",proc[i].pid,proc[i].bt,proc[i].pt,proc[i].tat,proc[i].wt);
    }
    wtSum = (float) wtSum / n ;
    printf("Average Waiting Time = %f",wtSum);
    return 0;
}
