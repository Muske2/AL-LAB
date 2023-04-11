#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Knapsack
{
    char name;
    int weight;
    int profit;
};
bool greedybyweight(Knapsack a ,Knapsack b)
{
    return a.weight<b.weight;
}
bool greedybyprofit(Knapsack a,Knapsack b)
{
    return a.profit>b.profit;
}
int main()
{
    int w,n,j=0,profit=0,w2;
    Knapsack k[20];
    char selected1[20],selected2[20];
    cout<<"Enter capacity of Knapsack: "<<endl;
    cin>>w;
    w2=w;
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    cout<<"Enter item details: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter name: "<<endl;
        cin>>k[i].name;
        cout<<"Enter weight: "<<endl;
        cin>>k[i].weight;
        cout<<"Enter profit: "<<endl;
        cin>>k[i].profit;
    }
    cout<<"---------------------------"<<endl;
    cout<<"GREEDY BY WEIGHT: "<<endl;
    sort(k,k+n,greedybyweight);
    for(int i=0;i<n;i++)
    {
        w=w-k[i].weight;
        if(w<0)
        {
            w=w+k[i].weight;
            continue;
        }
        selected1[j]=k[i].name;
        j++;
        profit+=k[i].profit;
    }
    cout<<"Items selected: "<<endl;
    for(int i=0;i<j;i++)
    {
        cout<<selected1[i]<<" ";
    }
    cout<<"\nTotal Profit: "<<profit<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"GREEDY BY PROFIT: "<<endl;
    sort(k,k+n,greedybyprofit);
    j=0;
    profit=0;
     for(int i=0;i<n;i++)
    {
        w2=w2-k[i].weight;
        if(w2<0)
        {
            w2=w2+k[i].weight;
            continue;
        }
        selected2[j]=k[i].name;
        j++;
        profit+=k[i].profit;
    }
    cout<<"Items selected: "<<endl;
    for(int i=0;i<j;i++)
    {
        cout<<selected2[i]<<" ";
    }
    cout<<"\nTotal Profit: "<<profit<<endl;
}

