#include<iostream>
using namespace std;
int v,e;
class Stack
{
public:
    int s[100];
    int top;
    Stack()
    {
        top=-1;
    }
    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else return false;
    }
    void push(int x)
    {
        if(top==99)
        {
            cout<<"Stack overflow."<<endl;
        }
        else
        {
            s[++top]=x;
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack underflow."<<endl;
        }
        else
        {
            return s[top--];
        }
    }
};
void dfs(int a[10][10],int src,int visited[],int &c)
{
    Stack s;
    c++;
    s.push(src);
    c++;
    int z;
    while(!s.isEmpty())
    {
        c++;
        z=s.pop();
        cout<<z<<"->";
        for(int i=1;i<=v;i++)
        {
            c++;
            if(a[z][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                c++;
                s.push(i);
                c++;
            }
        }
        c++;
        visited[z]=1;
    }
    c++;
}
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
    cout<<"ENTER SOURCE: "<<endl;
    cin>>src;
    dfs(a,src,visited,c);
    cout<<"DFS: "<<endl;
    cout<<"\nNumber of steps: "<<c;
}
