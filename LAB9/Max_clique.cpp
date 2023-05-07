#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int store[MAX], n;
int graph[MAX][MAX];
int d[MAX];
bool is_clique(int b)
{
    for (int i = 1; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
            if (graph[store[i]][store[j]] == 0)
                return false;
    }
    return true;
}

int maxCliques(int i, int l)
{
    int max_ = 0;
    for (int j = i + 1; j <= n; j++)
    {
        store[l] = j;
        if (is_clique(l + 1))
        {
            max_ = max(max_, l);
            max_ = max(max_, maxCliques(j, l + 1));
        }
    }
    return max_;
}
int main()
{
    int edges[20][2]={0},v,e,src,dest;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    n=e;
    for(int i=0;i<e;i++)
    {
        cout<<"Enter src: "<<endl;
        cin>>src;
        cout<<"Enter dest: "<<endl;
        cin>>dest;
        edges[i][0]=src;
        edges[i][1]=dest;
    }
    for (int i = 0; i < e; i++)
    {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        d[edges[i][0]]++;
        d[edges[i][1]]++;
    }
    cout<<"MAX CLIQUE: "<<maxCliques(0,1)<<endl;
    return 0;
}
