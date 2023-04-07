#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct ITEM
{
    char name;
    float profit;
    float weight;
    float profit_density;
};
bool pdsort(ITEM a,ITEM b)
{
    return a.profit_density>b.profit_density;
}
int main()
{
    int n,i;
    int rem;
    float total_profit=0,capacity;
    cout<<"Enter capacity of knapsack: "<<endl;
    cin>>capacity;
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    char selected[n];
    ITEM item[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter item: "<<endl;
        cin>>item[i].name;
        cout<<"Enter profit: "<<endl;
        cin>>item[i].profit;
        cout<<"Enter weight: "<<endl;
        cin>>item[i].weight;
        item[i].profit_density=item[i].profit/item[i].weight;
    }
    sort(item,item+n,pdsort);
    i=0;
    while(capacity>=0 && i<n)
    {
        capacity-=item[i].weight;
        if(capacity<0)
        {
            capacity+=item[i].weight;
            total_profit+=(item[i].profit*capacity/item[i].weight);
            rem=(capacity/item[i].weight);
             capacity-=rem*item[i].weight;
        }
        else
       {
           total_profit+=item[i].profit;
       }
        selected[i]=item[i].name;
        i++;
    }
    cout<<"SELECTED ITEMS IN KNAPSACK: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<selected[i]<<" ";
    }
    cout<<"TOTAL PROFIT: "<<total_profit<<endl;
}
