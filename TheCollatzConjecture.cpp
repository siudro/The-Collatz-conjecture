#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "pthread.h"
using namespace std;

int collatz(int num){
  int count=0;
  if (num<=0){
    printf("the  < 0");
  return 0;
  }

while(count!=10000){
  if (num==1){
    printf("%i",num);
    return 0;
  }
  else if (num%2==0){
    printf("%i",num);
    num/=2;
    printf("  ");
  }

  else{
    printf("%i",num);
    num=num*3+1;
    printf("   ");
  }
  count++;
}
return 0;
}

int main(){

  int num,stat=0;
  cout<<"what num";
  cin>>num;
  pid_t pid;

  pid=fork();
  if(pid==-1){
    printf("child did not created");
  }

  else if (pid==0){
printf(":");
collatz(num);


}
else 
{
wait(&stat);
printf("\n");
}
}
