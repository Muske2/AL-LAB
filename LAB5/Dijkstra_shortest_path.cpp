#include<iostream>
#define infinity 9999
using namespace std;
void dijkstra(int cost[][10],int v,int src)
{
    int distance[v],min_index=src,min_distance,prev_index[v],path[v];
    bool visited[v];
    for(int i=1;i<=v;i++)
    {
        visited[i]=false;
        distance[i]=infinity;
        prev_index[i]=-1;
    }
    visited[src]=true;
    distance[src]=0;
   // path[x++]=src;
    prev_index[src]=-1;
    for(int edge=0;edge<v-1;edge++)
    {
        min_distance=infinity;
       for(int i=1;i<=v;i++)
       {
           if(!visited[i]&& distance[i]<min_distance)
           {
               min_distance=distance[i];
               min_index=i;
           }
       }
        visited[min_index]=true;
        for(int i=1;i<=v;i++)
        {
            if(!visited[i]&&cost[min_index][i]&&cost[min_index][i]+distance[min_index]<distance[i])
            {
                distance[i]=cost[min_index][i]+distance[min_index];
                prev_index[i]=min_index;
                //path[x++]=i;
            }
        }
    }
   cout << "SHORTEST PATH(previous index) -> ";
for (int i=1;i<=v;i++) {
    cout << i<< "(" << prev_index[i] << ") ";
}
cout << endl;
    cout << "DISTANCE -> ";
    for (int i = 1; i <= v; i++) {
        cout << distance[i] << " ";
    }
    cout << endl;
}
int main()
{
     int e,v,start;
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
    cout<<"ENTER SOURCE: "<<endl;
    cin>>start;
    dijkstra(cost,v,start);
}
