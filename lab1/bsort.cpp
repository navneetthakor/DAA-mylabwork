#include<iostream>
using namespace std;

int main(){
    int n,temp, flag = 1;
    cout<<"Enter the no of elements : ";
    cin>>n;
    int arr[n];

    //loop to assign vlaues 
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        arr[i]=n-i;
    }
    cout<<"Values assigned...."<<endl;

    cout<<"sorting started...."<<endl;
    // loop to short them
    for(int i=0; i<n; i++){
        if(flag == 1){
            flag = 0;
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        }else{
            break;
        }
    }

    cout<<"Sorting completed...."<<endl;
    cout<<"Here is your sorted array...."<<endl;
    cout<<"Assigning values...."<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}