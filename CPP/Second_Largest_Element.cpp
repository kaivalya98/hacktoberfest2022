//Second largest element

#include<iostream>
using namespace std;

//time complexity: O(n^2)
void bsort(int arr[],int n)
{
    int t;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    
    cout<<"Second largest element :"<<arr[n-2]<<"\n";
}

// time complexity: O(n)
void secondLargest(int arr[], int n){
    int largest=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>largest) largest=arr[i];
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==largest) count++;
    }
    if(count>1){
        cout<<"Second largest element: "<<largest<<"\n"; return;
    }
    int sec=arr[0];
    for(int i=0;i<n;i++){
        if(sec<arr[i] and arr[i]<largest) sec=arr[i];
    }
    cout<<"Second largest element: "<<sec<<"\n"; return;
}

int main()
{
    cout<<"Enter size of array :";
    int n;
    cin>>n;
    int arr[n];
    
    cout<<"Enter array elements :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Using binary sort: \n";
    bsort(arr,n);
    cout<<"Using iterative method: \n";
    secondLargest(arr,n);
    
}
