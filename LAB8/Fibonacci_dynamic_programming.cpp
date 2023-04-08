#include<iostream>
using namespace std;
void fibo(int n)
{
   int fib[n+2],i;
   fib[0]=0;fib[1]=1;
   cout<<"FIBONACCI SERIES: \n"<<endl;
   cout<<fib[0]<<" "<<fib[1]<<" ";
   for(i=2;i<n;i++)
   {
       fib[i]=fib[i-1]+fib[i-2];
       cout<<fib[i]<<" ";
   }
}
int main()
{
    int n;
    cout<<"Enter the length of fibonacci series: "<<endl;
    cin>>n;
    fibo(n);
}
