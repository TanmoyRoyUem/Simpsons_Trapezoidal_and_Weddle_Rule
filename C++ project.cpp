#include <iostream>
#include<cmath>
#include <iomanip>
#include<stdio.h>
#define b 2.0
#define a 0.0
double f(double x){return pow(x,3);}
using namespace std;
void weddle(double h,int n){
  double sum=0.0;
  int i,pos=1;
  for(i=0;i<=n;i++){
    if((i==0)||(i==n))
      sum+=f(i*h);
    else if(i%(2) !=0){
      sum+=(pos%(2)!=0)?((5)*f(i*h)):((6)*f(i*h));
      pos++;
    }
    else
      sum+=f(i*h);
  }
  // cout<<"Resultant approximation="<<0.3*h*sum<<endl;
  printf("Resultant approximation %lf \n",0.3*h*sum);
}
void simpsons(double h,int n){
  double sum=0.0;
  int i;
  for(i=0;i<=n;i++){
    if((i==0)||(i==n))
      sum+=f(i*h);
    else if(i%2!= 0)
      sum+=4.0*f(i*h);
    else
      sum+=2.0*f(i*h);

  }
  // cout<<"Resultant approximation="<<((h/3)*sum)<<endl;
  printf("Resultant approximation %lf \n",(h/3)*sum);
}
void trapezoidal(double h,int n){
  double sum=0.0,x=a;
  int i;
  for(i=0;i<=n;i++){
    // cout<<i<<endl;
    if((i==0)||(i==n)){
     sum+=f(i*h);
    }
    else
      sum+=(2.0)*f(i*h);
  }
  printf("Resultant approximation %lf \n",(h/2)*sum);
  }
int main() {
  int ch,n;
  double i,h;
  cout<<"**********************************************************"<<endl;
  while(1){
    cout<<"Enter no. of intervals:\n";
    cin>>n;
    h=((b-a)/n);
    cout<<"X\t"<<"Y"<<endl;
    cout<<setprecision(3);
    for(i=a;i<=b;i+=h){
      cout<<i<<"\t"<<f(i)<<endl;
    }
    if((n%6 ==0)&&(n%2==0)){
      ch=3;

    }
    else if(n%2==0){
      ch=2;

    }
    else{
      ch=1;
      cout<<"We use Trapezoidal rule"<<endl;
    }
    switch(ch){
      case 1:
        trapezoidal(h,n);
        break;
      case 2:
        cout<<"Press 1:for Simpsons"<<endl<<"Press 2:for trapezoidal"<<endl;
        cin>>ch;
        if (ch==1)
        simpsons(h,n);
        else if(ch==2)
        trapezoidal(h,n);
        break;
      case 3:
        cout<<"Press 1: for Weddle's rule"<<endl<<"Press 2:for Simpson's rule"<<endl<<"Press 3:for trapezoidal rule"<<endl;
        cin>>ch;
        if (ch==1)
        weddle(h,n);
        else if(ch==2)
        simpsons(h,n);
        else if(ch==3)
        trapezoidal(h,n);
        break;
    }
    cout<<"Press 1 to exit"<<endl<<"Press any other integer to continue"<<endl;
    cin>>ch;
    cout<<"**********************************************************"<<endl;
    if(ch==1)
      exit(0);

  }
}

