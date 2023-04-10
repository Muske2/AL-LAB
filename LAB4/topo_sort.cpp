#include <iostream>
#include <vector>
#include <queue>
//#include <stack>
using namespace std;
int main()
{
    int v,e,counts=0;
    cout<<"Enter number of vertex and edges:";
    cin>>v>>e;
    vector <vector <int> > adj(v);
    vector <int> indegree(v,0);
    for (int i=0;i<e;i++)
    {
        int v1,v2;
        cout<<"Enter source and desti: ";
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        indegree[v2]++;
    }
    queue <int> q;
    //stack <int> q;
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)    q.push(i);

    }
    while(!q.empty())
    {

      int x=q.front();
      //int x=q.top();
      q.pop();
      cout<<x<<" ";
      counts++;
      for(auto it:adj[x])
      {
          indegree[it]--;
          if(indegree[it]==0)
            q.push(it);
      }
    }
    if(counts==(v))  cout<<"Topo Sort Exists ,Cycle not";
    else cout<<"Topo sort doesnt exist, hence there is a cycle in the graph";

    return 0;
}
