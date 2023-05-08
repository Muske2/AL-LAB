#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;
int main()
{
    int x,a[20],t,count=0;
    cout<<"Enter number of terms: "<<endl;
    cin>>x;
    cout<<"ENTER: "<<endl;
    for(int i=0;i<x;i++)
    {
        cin>>a[i];
    }
    auto start=high_resolution_clock::now();
    for(int i=0;i<x-1;i++)
    {
        count++;
        for(int j=i+1;j<x;j++)
        {
            count++;
            count++;
            if(a[i]>a[j])
            {
                count++;
                t=a[i];
                count++;
                a[i]=a[j];
                count++;
                a[j]=t;
            }

        }
        count++;
    }
    count++;
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<nanoseconds>(stop-start);
    cout<<"After Sorting: "<<endl;
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\ncount: "<<count<<endl;
    cout<<"Time: "<<duration.count()<<"ms"<<endl;
}
