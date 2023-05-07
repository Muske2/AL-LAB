#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define V 20
void tsp(int graph[][V],bool visited[],int n,int count,int cost,int curindex,int &ans)
{
    if(n==count && graph[curindex][0])
    {
        ans=min(ans,cost+graph[curindex][0]);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && graph[curindex][i])
        {
            visited[i]=true;
            tsp(graph,visited,n,count+1,cost+graph[curindex][i],i,ans);
            visited[i]=false;
        }
    }
}
int main()
{
    int v,graph[V][V];
    cout<<"Enter number of cities: "<<endl;
    cin>>v;
    cout<<"Enter adjacency matrix: "<<endl;
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>graph[i][j];
        }
    }
    bool visited[v];
    int ans=999;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    visited[0]=true;
    tsp(graph,visited,v,1,0,0,ans);
    cout<<"Total cost: "<<ans<<endl;
}
