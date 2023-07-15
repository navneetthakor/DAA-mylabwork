#include<iostream>
using namespace std;

int main()
{
    int n,temp;
    cout<<"Enter the no of elements : ";
    cin>>n;
    int arr[n];

    //loop to assign vlaues 
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        arr[i]=n-i;
    }

    cout<<"iSorting startd...."<<endl;
    for(int i=1; i<n; i++){
        for(int j=i; j>0; j--){
            if(arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j]=arr[j-1];
                arr[j-1] = temp;
            }else{
                break;
            }
        }
    }
    cout<<"iSorting complete...."<<endl;
    cout<<"Here is your sorted array...."<<endl;
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}