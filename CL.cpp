#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
using namespace std;

int collatz(int num){
  int count=0;
  if (num<=0){
    cout<<"the number is < 0"<<endl;
  return 0;
  }//end if 

while(count!=10000){
  if (num==1){
    cout<<"%i"<<num<<endl;
    return 0;
  }// end if
  else if (num%2==0){
    cout<<num;
    num/=2;
    cout<<"  ";
  }// end else if

  else{
    cout<<num;
    num=num*3+1;
    cout<<"   ";
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
    cout<<"child did not created"<<endl;
  }// end if 

  else if (pid==0){
    cout<<":";
    collatz(num);
  }//end else if 
  else{
    wait(&stat);
    cout<<endl;
   }// end else
}//end main
