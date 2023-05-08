#include<iostream>
using namespace std;
int v,e;
class Q
{
public:
    int a[100];
    int f,r;
    Q()
    {
        f=-1;
        r=0;
    }
    bool isEmpty()
    {
        if(f==r)
        {
            return true;
        }
        else return false;
    }
    void enqueue(int x)
    {
        if(r==99)
        {
            cout<<"Queue is full."<<endl;
        }
        else if(r==0)
        {
            a[r++]=x;
            f=0;
        }
        else
        {
            a[r++]=x;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty."<<endl;
        }
        else
        {
            return a[f++];
        }
    }
};
void bfs(int a[10][10],int src,int visited[],int &c)
{
    Q q;
    c++;
    int z;
    q.enqueue(src);
    c++;
    while(!q.isEmpty())
    {
        c++;
        z=q.dequeue();
        c++;
        cout<<z<<"->";
        for(int i=0;i<v;i++)
        {
            c++;
            if(a[z-1][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                c++;
                q.enqueue(i+1);
                c++;
            }
        }
        c++;
        visited[z-1]=1;
        c++;
    }
    c++;
}
int main()
{
    int a[10][10],src,p,q,visited[10],i,j,c=0;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
        a[i][j]=0;
    for(i=0;i<v;i++)
        visited[i]=0;
    for(i=1;i<=e;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>p;
        cout<<"Enter destination: "<<endl;
        cin>>q;
        a[p-1][q-1]=1;
    }
    cout<<"Enter SOURCE: "<<endl;
    cin>>src;
    cout<<"\nBFS: "<<endl;
    bfs(a,src,visited,c);
    cout<<"NULL"<<"\nNumber of steps: "<<c<<endl;
}
