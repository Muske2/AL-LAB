#include<iostream>
#include<bits/stdc++.h>
#define MAX 20
using namespace std;
int graph[MAX][MAX],d[MAX],n,store[MAX];
vector<int>vertices;
bool isclique(int b)
{
    for(int i=1;i<b;i++)
    {
        for(int j=i+1;j<b;j++)
        {
            if(graph[store[i]][store[j]]==0)
            {
                return false;
            }
        }
    }
    vertices.push_back(b-1);
    return true;
}
int maxclique(int i,int l)
{
    int maxval=0;
    for(int j=i+1;j<=n;j++)
    {
        store[l]=j;
        if(isclique(l+1))
        {
            maxval=max(maxval,l);
            maxval=max(maxval,maxclique(j,l+1));
        }
    }
    return maxval;
}
int main()
{
    int src,dest,x;
    cout<<"Enter number of edges: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>src;
        cout<<"Enter destination: "<<endl;
        cin>>dest;
        graph[src][dest]=1;
        graph[dest][src]=1;
        d[src]++;
        d[dest]++;
    }
    x=maxclique(0,1);
    cout<<"MAX CLIQUE: "<<x<<endl;
   vertices.resize(x);
     cout << "Clique vertices: ";
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i] << " ";
    }
    cout << endl;
}
