
#include <stdio.h>

struct process {
  int pid;
  int bt;
  int wt;
  int ct;
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
        proc[i].pid = i+1;
    }
    
    //Sort burst time
    
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(proc[i].bt>proc[j].bt){
                temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }

    //calculate ct and wt
    proc[0].ct = proc[0].bt;
    proc[0].wt = 0;
    for(i=1;i<n;i++){
        proc[i].ct = proc[i-1].ct + proc[i].bt;
        
        proc[i].wt = proc[i].ct - proc[i].bt;
    }
    
    
    printf("PID\tBT\tCT\tWT\t");
    for(i=0;i<n;i++){
        printf("\n%d\t%d\t%d\t%d",proc[i].pid,proc[i].bt,proc[i].ct,proc[i].wt);
    }
    
    return 0;
}
