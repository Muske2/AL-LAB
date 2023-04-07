#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int inf=9999;
class UGraph{
    private:
    int** adj;
    int n;
    public:
    UGraph(int numb){
        n = numb+1;
        adj = new int*[n];
        for(int i=0;i<n; ++i)
            adj[i] = new int[n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++)
                adj[i][j] = inf;
        }
    }
    void addVertex(int src, int dest, int cost){
        adj[src][dest]=cost;
        adj[dest][src]=cost;
    }
    pair<int,int> minimum(bool selected[]){
        int min=inf;
        int p1=0;
        int p2=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(selected[i] && !selected[j] && adj[i][j]<min  && i!=j){
                    min=adj[i][j];
                    p1=i;
                    p2=j;
                }
            }
        }
        return make_pair(p1,p2);
    }
    void PrimMST(){
        bool selected[n]={false};
        selected[1] = true;
        int edges = 0;
        queue <pair<int,int> > solution;
        while(edges!=n-2){ //and not (n-1) because n is one larger due to 1-indexing
            pair<int, int> small = minimum(selected);
            if(small.first==0)
                break;
            edges++;
            selected[small.second]=true;
            solution.push(small);
        }
        if(edges!=n-2)
            cout<<"Spanning Tree cannot be constructed";
        else{
            while(!solution.empty()){
                int a = solution.front().first;
                int b = solution.front().second;
                solution.pop();
                cout<<"("<<a<<", "<<b<<") -> "<<adj[a][b]<<"\n";
            }
        }
    }

};

int main(){
    int n;
    cout<<"Enter size:";
    cin>>n;
    UGraph G(n);
    cout<<"Enter edges and cost:(<-1, -1> to stop)"<<endl;
    int a, b, cost;
    while(true){
        cin>>a>>b>>cost;
        if(a!=-1 && b!=-1)
            G.addVertex(a,b,cost);
        else
            break;
    }
    G.PrimMST();
}
