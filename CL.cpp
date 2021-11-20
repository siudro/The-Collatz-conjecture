#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int collatz(int num){
  int count=0;
  if (num<=0){
    printf("the  < 0");
  return 0;
  }//end if 

while(count!=10000){
  if (num==1){
    printf("%i",num);
    return 0;
  }// end if
  else if (num%2==0){
    printf("%i",num);
    num/=2;
    printf("  ");
  }// end else if

  else{
    printf("%i",num);
    num=num*3+1;
    printf("   ");
  }// end else
  count++;
}//end while
return 0;
}// end collatz

int main(){

  int num,stat=0;
  cout<<"please enter the number you want to test ";
  cin>>num;
  pid_t pid;

  pid=fork();
  if(pid==-1){
    printf("child did not created");
  }// end if 

  else if (pid==0){
    printf(":");
    collatz(num);
  }//end else if 
  else{
    wait(&stat);
    printf("\n");
   }// end else
}//end main
