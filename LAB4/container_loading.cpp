#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Container
{
    char name;
    int weight;
};
bool compare(Container a,Container b)
{
    return (a.weight<b.weight);
}
int main()
{
    Container c[15];
    char selected[15];
    int i,j=0,n;
    int tot=0,w;
    cout<<"Enter capacity of wagon: "<<endl;
    cin>>w;
    cout<<"Enter number of containers: "<<endl;
    cin>>n;
    cout<<"Enter name and weight of container: "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"Enter name: ";
        cin>>c[i].name;
        cout<<"Enter weight: ";
        cin>>c[i].weight;
    }
    sort(c,c+n,compare);
    for(i=0;i<n;i++)
    {
        w=w-c[i].weight;
        if(w<0)
        {
            w=w+c[i].weight;
            break;
        }
        selected[j]=c[i].name;
        j++;
        tot++;
    }
    cout<<"TOTAL NUMBER OF CONATINERS LOADED: "<<tot<<endl;
    cout<<"Containers loaded: "<<endl;
    for(int i=0;i<tot;i++)
    {
        cout<<selected[i]<<" ";
    }
}

