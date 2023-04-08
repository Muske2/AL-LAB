#include<iostream>
using namespace std;
int BinarySearch(int arr[],int low,int high,int key)
{
    while(low<=high)
    {
         int mid=(low+high)/2;
         if(arr[mid]==key)
         {
             return mid;
         }
         else if(arr[mid]>key)
         {
             high=mid-1;
         }
         else
         {
             low=mid+1;
         }
    }
    return -99;
}
int main()
{
    int arr[10],key,n;
    cout<<"Enter size of array: "<<endl;
    cin>>n;
    cout<<"Enter terms in ascending order: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter element to be searched: "<<endl;
    cin>>key;
    int found=BinarySearch(arr,0,n-1,key);
    if(found==-99)
    {
        cout<<"Element absent in the array."<<endl;
    }
    else
    {
        cout<<"Search successful! Element found in position: "<<found<<endl;
    }
}
