#include<stdio.h>
int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n,r;
void input();
void show();
void cal();


int main(){
  int i,j;
  input();
  show();
  cal();
  return 0;
}

void input(){
  int i,j;
  printf("Enter the no of processes : \t");
  scanf("%d",&n);
  printf("Enter the no of resources instances : \t");
  scanf("%d",&r);
  printf("Enter the max matrix \n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      scanf("%d",&max[i][j]);
    }
  }
  printf("Enter the allocation matrix\n");
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      scanf("%d",&alloc[i][j]);
    }
  }
  printf("Enter the resources available \n");
  for(j=0;j<r;j++){
    scanf("%d",&avail[j]);
  }
}

void show(){
  int i,j;
  printf("Process\tAllocation\tMax\tAvailable\t");
  for(i=0;i<n;i++){
    printf("\nP%d\t",i+1);
    for(j=0;j<r;j++){
      printf("%d ",alloc[i][j]);
    }
    printf("\t\t");
    for(j=0;j<r;j++){
      printf("%d ",max[i][j]);
    }
    printf("\t");
    if(i==0){
      for(j=0;j<r;j++)
        printf("%d ",avail[j]);
    }
  }
}

void cal(){
  int finish[100],temp,need[100][100],flag=1,k,cl=0; 
  int i,j;
  for(i=0;i<n;i++){
    finish[i]=0; //initiate all processes's finish to 0
  }
  for(i=0;i<n;i++){
    for(j=0;j<r;j++){
      need[i][j]=max[i][j]-alloc[i][j]; //calculate need
    }
  }
  printf("\n");
  while(flag){
    flag=0;
    for(i=0;i<n;i++){
      int c=0; //used to count the resource that satisfies the need
      for(j=0;j<r;j++){
        if((finish[i]==0)&&(need[i][j]<=avail[j])){
          c++;
          if(c==r){  //if all resources instances are satisfied
            for(k=0;k<r;k++){
              avail[k]+=alloc[i][j]; //add allocated to available
              finish[i]=1;  //set process state as finished
              flag=1; //set flag 1 so next process can be checked
            }
            printf("P%d->",i+1);  //print sequence
          }
        }
      }
    }
  }
  for(i=0;i<n;i++){
    if(finish[i]==1){ //if process finished increment cl
      cl++;
    }
  }
  if(cl==n){  //checks if all process are executed
    printf("\nThe System is in safe state");
  }
  else{
    printf("System is in unsafe state");
  }
}
