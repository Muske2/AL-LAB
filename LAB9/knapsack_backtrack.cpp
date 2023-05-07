#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>ans,weight,profit;
int capacity,n,maxval=-1;
void knapsack(int index,vector<int>&curans,int curW,int curP)
{
    if(curW>capacity)
    {
        return;
    }
    if(n==index)
    {
        if(curP>maxval)
        {
            maxval=curP;
            ans=curans;
        }
        return;
    }
    curans[index]=0;
    knapsack(index+1,curans,curW,curP);
    curans[index]=1;
    knapsack(index+1,curans,curW+weight[index],curP+profit[index]);
}
int main()
{
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    profit.resize(n);
    weight.resize(n);
    ans.resize(n);
    cout<<"Enter capacity of knapsack: "<<endl;
    cin>>capacity;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter profit of item "<<i+1<<" : "<<endl;
        cin>>profit[i];
        cout<<"Enter weight of item "<<i+1<<" : "<<endl;
        cin>>weight[i];
    }
    vector<int>curans(n);
    knapsack(0,curans,0,0);
    cout<<"Total profit: "<<maxval<<endl;
    cout<<"Items selected: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x"<<i+1<<"   ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        if(ans[i]==0)
            cout<<"0    ";
        else
            cout<<"1    ";
    }
    cout<<endl;
}
