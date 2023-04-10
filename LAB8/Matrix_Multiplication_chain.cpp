#include<iostream>
using namespace std;
struct MATRIX
{
    int row;
    int col;
};
void traceback(int s[][8],int i,int j)
{
    if(i==j)
    {
        return;
    }
    traceback(s,i,s[i][j]);
    traceback(s,s[i][j]+1,j);
    cout<<"Multiply M"<<i<<","<<s[i][j]<<" and M"<<s[i][j]+1<<","<<j<<endl;
}
int main()
{
    int n,i,j,k,key=0,start;
    cout<<"Enter number of matrices: "<<endl;
    cin>>n;
    int P[n+1];
    int min,m[n+1][n+1],s[8][8];
    MATRIX mat[n+1];
    for(i=1;i<=n;i++)
    {
        cout<<"Enter number of rows in matrix "<<i<<" :"<<endl;
        cin>>mat[i].row;
        cout<<"Enter number of columns in matrix "<<i<<" :"<<endl;
        cin>>mat[i].col;
    }
    for(i=1;i<=n;i++)
    {
        P[i-1]=mat[i].row;
    }
    P[n]=mat[n].col;
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            s[i][j]=0;
            m[i][j]=0;
        }
    }
    i=0,j=0,start=i;
    while(i<=n && j<=n)
    {
        if(j<=i)
            {
                m[i][j]=0;
                s[i][j]=0;
            }
            else if(j>i)
            {
                min=9999;
                for(k=i;k<j;k++)
                {
                    if(min>m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j])
                    {
                        min=m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j];
                        key=k;
                    }
                }
                m[i][j]=min;
                s[i][j]=key;
            }
            if(i<=n && j==n)
            {
                i=1;
                j=++start;
                continue;
            }
            i++;
            j++;
    }
    cout<<"M MATRIX: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"S MATRIX: "<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"TRACEBACK"<<endl;
    traceback(s,1,n);
}
//O(n^3)
