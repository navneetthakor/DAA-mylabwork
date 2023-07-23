#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v, int left, int right){
    // choosing our pivot 
    int pivot = v[right];

    //temperory variable to use for swaping
    int n = left;
    int temp;

    // loop to starting swaping 
    for(int i=left; i<right; i++){
        if(v[i]<pivot){
            temp = v[i];
            v[i] = v[n];
            v[n] = temp;
            n++;
        }
    }

    // putting pivot to it's right position 
   
        temp = v[right];
        v[right] = v[n];
        v[n] = temp;
        cout<<"it's n : "<<n<<endl;
        return n;
}

void myQuickSort(vector<int> &v, int left, int right){
    if(left<right){
        // first creating partitions
        int p = partition(v,left,right);
        cout<<"it's P : " <<p<<endl;

        // now sorting each patitions sepratly
        myQuickSort(v,left,p-1);
        myQuickSort(v,p+1, right);
        cout<<"Seprate : "<<p<<endl;
        for(int i=left;i<right;i++)
        {
            cout<<v[i]<<endl;
        }
    }
}

int main(){
    vector<int> v = {9,8,7,6,5,4,3,2,1,0};

    myQuickSort(v,0,v.size()-1);
    cout<<"After sort : "<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;
    }
}