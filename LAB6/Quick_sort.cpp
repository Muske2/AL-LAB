#include<iostream>
using namespace std;
int partition(int *,int,int);
void quicksort(int arr[],int low,int high)
{
     int q;
     if(low<high)
     {
         q=partition(arr,low,high);
         quicksort(arr,low,q-1);
         quicksort(arr,q+1,high);
     }
}
int partition(int arr[],int low,int high)
{
    int pivot,i,temp;
    pivot=arr[high];
    i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return (i+1);
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
    quicksort(arr,0,n-1);
    cout<<"SORTED ARRAY: "<<endl;
     for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
// average-case time complexity of O(n log n).
// However, in the worst case (when the pivot is always the smallest or largest element), the time complexity can be O(n^2).
