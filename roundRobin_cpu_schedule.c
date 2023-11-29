#include<stdio.h>


struct process {
    int pid;
    int bt;
    int ct;
    int rem_bt;
    int tat;
    int wt;
};

int main(){
    int n,i,tq;
    printf("Enter no of processes : ");
    scanf("%d",&n);
    printf("Enter time quantum : " );
    scanf("%d",&tq);
    struct process proc[n]; 
    printf("Enter Burst Time of each processes \n");
    for(i=0;i<n;i++){
        printf("Process %d : ",i+1);
        scanf("%d",&proc[i].bt);
        
        proc[i].rem_bt = proc[i].bt;
        proc[i].pid = i+1;
        
    }
    
    int time = 0;
    
    while(1){
        int flag = 0;
        for(i=0;i<n;i++){
            if(proc[i].rem_bt > 0){
                flag = 1;
                if (proc[i].rem_bt > tq){
                    time += tq;
                    proc[i].rem_bt -= tq;
                }
                else{
                    time += proc[i].rem_bt;
                    proc[i].wt = time - proc[i].bt;
                    proc[i].rem_bt = 0;
                }
            }
        }
        
        if(flag == 0){
            break;
        }
    }
    
    for(i=0;i<n;i++){
        proc[i].tat = proc[i].wt + proc[i].bt;
    }
    
    printf("PID\tBT\tTAT\tWT\n");
    
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\n",proc[i].pid,proc[i].bt,proc[i].tat,proc[i].wt);
    }
    
    return 0;
}
