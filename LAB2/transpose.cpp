#include<iostream>
using namespace std;
int v,e;
int main()
{
    int a[10][10],visited[10],c=0,p,q,i,j,src;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    for(i=1;i<=v;i++)
    {
        visited[i]=0;
    }
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
    cout<<"Adjacency Matrix: "<<endl;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    int m[10][10];
     for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            m[i][j]=a[j][i];
        }
    }
    cout<<"\nTranspose: "<<endl;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}
