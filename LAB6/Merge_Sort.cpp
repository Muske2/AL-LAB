#include<iostream>
using namespace std;
void merge(int*,int,int,int);
void mergesort(int arr[],int l,int r)//it divides the array
{
    int q;
    if(l<r)
    {
        q=l+(r-l)/2;//we can put q=(l+r)/2 also but it will give integer overflow in case of large integer values of l and r.
        mergesort(arr,l,q);
        mergesort(arr,q+1,r);
        merge(arr,l,q,r);
    }
}
void merge(int arr[],int l,int m,int r)//it combines the 2 divided arrays
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}
int main()
{
    int n;
    cout<<"Enter number of terms in array: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter terms: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergesort(arr,0,n-1);
    cout<<"SORTED ARRAY: "<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
//The Merge Sort algorithm has a time complexity of O(n log n) in all cases.
