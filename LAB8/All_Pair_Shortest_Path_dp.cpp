#include<iostream>
#define infinity 9999
using namespace std;
int min(int a,int b)
{
    return (a<b)?a:b;
}
void shortest_path(int arr[][10],int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                {
                    arr[i][j]=0;
                }
                else
                {
                 arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
    }
    cout<<"\nAll pair shortest paths are"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<i<<"--->"<<j<<" "<<arr[i][j]<<endl;
        }
        cout<<endl;
    }
}
int main()
{
    int v,e,src,dest,distance;
    cout<<"Enter number of vertices: "<<endl;
    cin>>v;
    int arr[10][10];
    cout<<"Enter number of edges: "<<endl;
    cin>>e;
    for(int i=1;i<=v;i++)
    {
        for(int j=1;j<=v;j++)
        {
            arr[i][j]=infinity;
        }
    }
    for(int i=0;i<e;i++)
    {
        cout<<"Enter source: "<<endl;
        cin>>src;
        cout<<"Enter distance: "<<endl;
        cin>>dest;
        cout<<"Enter distance: "<<endl;
        cin>>distance;
        arr[src][dest]=distance;
    }
    shortest_path(arr,v);
}
