#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Task
{
    public:
    int start,finish;
};
bool compare(Task t1,Task t2)
{
    return (t1.start<t2.start);
}
void printtasks(Task a[],int n)
{
    sort(a,a+n,compare);
    int i,j,m=0;
    bool selected[n];
    for(i=0;i<n;i++)
    {
        selected[i]=false;
    }
    for(i=0;i<n;i++)
    {
        if(selected[i])
            continue;
        cout<<"----------------------------------------"<<endl;
        cout<<"MACHINE SCHEDULING FOR MACHINE "<<m+1<<":"<<endl;
        cout<<"("<<a[i].start<<","<<a[i].finish<<")"<<endl;
        for(j=i+1;j<n;j++)
        {
            if(selected[j])
                continue;
            if(a[i].finish<=a[j].start)
            {
                i=j;
                selected[j]=1;
                cout<<"("<<a[j].start<<","<<a[j].finish<<")"<<endl;
            }
        }
        i=++m;
        cout<<"----------------------------------------"<<endl;
    }
    cout<<"Total number of machines used: "<<m<<endl;
}
int main() {
    Task arr[10];
    int n;
    cout<<"Enter the number of Total Number Tasks";
     cin>>n;
     cout<<"Enter Start and Finish time of each machine";
     for(int i=0;i<n;i++)
        cin>>arr[i].start>>arr[i].finish;
     printtasks(arr, n);
      return 0;
      }

