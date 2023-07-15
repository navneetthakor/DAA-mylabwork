#include<iostream>
using namespace std;

int main(){
    int n,min,temp;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];

    //loop to assign vlaues 
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        arr[i]=n-i;
    }


    // outer loop 
    for(int i=0; i<n-1;i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }

    cout<<"Here is your sorted array...."<<endl;
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}