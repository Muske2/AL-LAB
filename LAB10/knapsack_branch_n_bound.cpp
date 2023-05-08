#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,finalprofit=0,finalweight=0,capacity;
vector<int>profit,weight,selected,sel;
int Bound(int,int,int);
int Bound(int k,int cp,int cw)
{
    int a,b;
    a=cp;
    b=cw;
    for(int i=k+1;i<=n;i++)
    {
        b=b+weight[i];
        if(b<=capacity)
        {
            a=a+profit[i];
        }
        else
            return (a+(1-(b-capacity)/weight[i])*profit[i]);
    }
    return a;
}
void Knap(int k,int cp,int cw)
{
    if(cw+weight[k]<=capacity)
    {
        sel[k]=1;
        if(k<n)
        {
            Knap(k+1,cp+profit[k],cw+weight[k]);
        }
        if(cp+profit[k]>finalprofit && k==n)
        {
            finalprofit=cp+profit[k];
            finalweight=cw+weight[k];
            for(int j=1;j<=k;j++)
            {
                selected[j]=sel[j];
            }
        }
    }
    if(Bound(k,cp,cw)>=finalprofit)
    {
        sel[k]=0;
        if(k<n)
        {
            Knap(k+1,cp,cw);
        }
        if(cp>finalprofit && k==n)
        {
            finalprofit=cp;
            finalweight=cw;
            for(int j=1;j<=k;j++)
            {
                selected[j]=sel[j];
            }
        }
    }
}
int main()
{
    cout<<"\nEnter number of elements: ";
	cin>>n;
	profit.resize(n);
	weight.resize(n);
	selected.resize(n);
	sel.resize(n);
	cout<<"\nEnter elements in the descending order of P/W\n";
	for(int i=1;i<=n;i++)
	{
		cout<<"\nEnter profit of "<<i<<" element: ";
		cin>>profit[i];
		cout<<"\nEnter weight of "<<i<<" element: ";
		cin>>weight[i];
	}
	cout<<"\nEnter capacity of knapsack: ";
	cin>>capacity;
	Knap(1,0,0);
	cout<<"PROFIT: "<<finalprofit<<endl;
	cout<<"\nSolution is :\n";
	for(int i=1;i<=n;i++)
		cout<<"x["<<i<<"]= "<<selected[i]<<endl;
}
