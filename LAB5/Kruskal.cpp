#include<iostream>
#define infinity 9999
using namespace std;
int parent[10];
int find(int i)
{
    while(parent[i]!=i)
    {
        i=parent[i];
    }
    return i;
}
void UNION(int a,int b)
{
    int x,y;
    x=find(a);
    y=find(b);
    parent[x]=y;
}
void kruskal(int cost[][10],int V)
{
    int mincost=0;
    for(int i=1;i<=V;i++)
    {
        parent[i]=i;
    }
    int edge=0,a,b;
    cout<<"SELECTED EDGE\tCOST\n";
    while(edge!=V-1)
    {
        int min=infinity;
        a=-1;
        b=-1;
        for(int i=1;i<=V;i++)
        {
            for(int j=1;j<=V;j++)
            {
                if(min>cost[i][j] && find(i)!=find(j))
                {
                    min=cost[i][j];
                    a=i;
                    b=j;
                }
            }
        }
        UNION(a,b);
        cout<<"("<<a<<","<<b<<")\t\t"<<min<<'\n';
        edge++;
        mincost+=min;
    }
    cout<<"MINIMUM COST = "<<mincost;
}
int main()
{
    int e,v;
    int src,dest,x;
    int cost[10][10];
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            cost[i][j]=infinity;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>src;
        cout<<"Enter destination: "<<endl;
        cin>>dest;
        cout<<"Enter cost: "<<endl;
        cin>>x;
        cost[src][dest]=x;
        cost[dest][src]=x;//for undirected graph
    }
    kruskal(cost,v);
}
