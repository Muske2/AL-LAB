#include<iostream>
using namespace std;
struct ITEM
{
    int profit;
    int weight;
};
int max(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int m,n,i;
    cout<<"Enter capacity of knapsack: "<<endl;
    cin>>m;
    cout<<"Enter number of items: "<<endl;
    cin>>n;
    int profit[n],weight[n];
    int V[n+1][m+1];
    ITEM item[n+1];
    cout<<"Enter item profit and weight: "<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<"Enter profit: "<<endl;
        cin>>item[i].profit;
        cout<<"Enter weight: "<<endl;
        cin>>item[i].weight;
    }
    for(i=0;i<n+1;i++)
    {
        for(int w=0;w<m+1;w++)
        {
            if(i==0||w==0)
            {
                V[i][w]=0;
            }
            else if(w>=item[i].weight && i!=0)
            {
                V[i][w]=max(V[i-1][w],V[i-1][w-item[i].weight]+item[i].profit);
            }
            else
            {
                V[i][w]=V[i-1][w];
            }
        }
    }
    cout<<"TABULATION METHOD: "<<endl;
    for(i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            cout<<V[i][j]<<" ";
        }
        cout<<endl;
    }
    int maxprofit=V[n][m];
    cout<<"PROFIT: "<<maxprofit;
    cout<<"\nITEMS:\nx1 x2 x3 x4\n"<<endl;
    int selected[n]={0};
    int count=0,w=m;
    while(count!=n)
    {
      for(i=0;i<=n;i++)
    {
        if(V[i][w]==maxprofit)
        {
            selected[i]=1;
            break;
        }
    }
    count++;
    w-=item[i].weight;
    maxprofit-=item[i].profit;
    }
    for(int i=1;i<=n;i++)
    {
        cout<<selected[i]<<"  ";
    }
}
