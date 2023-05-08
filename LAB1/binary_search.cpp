#include<iostream>
#include<chrono>
using namespace std::chrono;
using namespace std;
static int c=0;
int Bin_Search(int a[],int x,int l,int h)
{
    int m;

    m=(l+h)/2;
    c++;
    c++;
    if(a[m]==x)
    {
        c++;
        return m;
    }
    if(l>h)
    {
        c++;
        return -99;
    }
    else if(a[m]<x)
    {
        c++;
        Bin_Search(a,x,m+1,h);
    }
    else if(a[m]>x)
    {
        c++;
        Bin_Search(a,x,l,m-1);
    }
}
int main()
{
    int mid,high,low,n,i,x,flag=0,a[20],cnt=0;
    cout<<"Enter number of terms: "<<endl;
    cin>>n;
    cout<<"ENTER SORTED ARRAY: "<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter element to be searched: "<<endl;
    cin>>x;
    auto start=high_resolution_clock::now();
    low=0;
    high=n-1;
    cnt++;
    while(low<=high)
    {
        cnt++;
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            cnt++;
            cout<<"Element found in position "<<mid<<endl;
            flag=1;
            break;
        }
        else if(a[mid]>x)
        {
            cnt++;
            high=mid-1;
        }
        else if(a[mid]<x)
        {
            cnt++;
            low=mid+1;
        }
    }
    cnt++;
    if(flag==0)
    {
        cout<<"Element not present in array."<<endl;
    }
        auto stop=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(stop-start);
        cout<<"Number of steps performed: "<<cnt<<endl;
        cout<<"Time taken: "<<duration.count()<<"ms"<<endl;
       /* cout<<"Enter term to be searched Recursively: "<<endl;
        cin>>x;
        int p;
       auto start=high_resolution_clock::now();
        p=Bin_Search(a,x,0,n-1);
        cout<<"Element found in position: "<<p<<endl;
        auto stop=high_resolution_clock::now();
        auto duration=duration_cast<microseconds>(stop-start);
        cout<<"Number of steps= "<<c<<endl;
        cout<<"Time taken: "<<duration.count()<<"ms"<<endl;*/
}

