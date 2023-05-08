#include<iostream>
using namespace std;
int v;
int mothervertex(int a[10][10],int src,int visited[])
{
    int c=0;
    int s[20],top=-1;
    s[++top]=src;
    while(top>=0)
    {
        int z=s[top--];
        c++;
        for(int i=1;i<=v;i++)
        {
            if(a[z][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                s[++top]=i;
            }
        }
        visited[z]=1;
    }
    return c;
}
int main()
{
    int a[10][10],e,visited[10],c=0,p,q,i,j,src;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            a[i][j]=0;
        }
    }
    for(i=1;i<=e;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>p;
        cout<<"Enter destination: "<<endl;
        cin>>q;
        a[p][q]=1;
    }
    cout<<"Mother vertex: "<<endl;
    for(i=1;i<=v;i++)
    {
     for(j=1;j<=v;j++)
    {
        visited[j]=0;
    }
        if(mothervertex(a,i,visited)==v)
        {
            cout<<i<<" ";
        }
    }
}

