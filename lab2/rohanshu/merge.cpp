#include<iostream>
#include <vector>
#include<cstdlib>
using  namespace std;

void vec_merge(vector<int>&v, int vec_begin, int vec_end, int mid){
    int sizeofleft =  mid - vec_begin;
    int sizeofright = vec_end - mid;

    vector <int> leftv = (v.begin() , v.begin() + mid);
    vector <int> rightv = (v.begin)() + mid + 1, v.end());

    int leftindex = 0, rightindex = 0, mergeindex = vec_begin;

    while(leftindex<=leftv.size() && rightindex<=rightv.size()){
        if(leftv[leftindex]<=rightv[rightindex]){
            v[mergeindex] = leftv[leftindex];
            leftindex++;
        }
        else{
            v[mergeindex] = rightv[rightindex];
            rightindex++;
        }
        mergeindex++;
    }
    // if left elements remains
    while(leftindex < leftv.size()){
        v[mergeindex] = leftv[leftindex];
        mergeindex++;
        leftindex++;
    }
    // if right elements remains
    while(rightindex < rightv.size()){
        v[mergeindex] = rightv[rightindex];
        mergeindex++;
        rightindex++;
    }
}

void mergesort(vector<int> &v,int vec_begin,int vec_end){
    if(vec_begin >= vec_end){
        return;
    }
    else{
        int mid = (vec_begin+vec_end)/2;
        mergesort(v, vec_begin , mid);
        mergesort(v , mid+1 , vec_end);
        vec_merge(v,vec_begin,vec_end,mid);
    }
}

int main(){
 vector <int> v = {2,6,3,1,4,5};
 mergesort(v,0,5);
 cout<<"Displaying sorted vector :\n";
 for(int i=0;i<6;i++){
    cout<<v[i]<<" ";
 }
return 0;
}
