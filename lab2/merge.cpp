#include<bits/stdc++.h>
using namespace std;



void myMerge(vector<int>v, int mybegin, int mid, int myend){
cout<<"1"<<endl;
    //creating left and right array
    vector<int> leftv = {v.begin(),v.begin() + mid};
    vector<int> rightv = {v.begin() + mid +1, v.end()};

    //creating some required variables
    int leftindex = 0;
    int righindex = 0;
    int mergeindex = mybegin;

    //loop to merge in v[mybegin .. myend]
    while(leftindex<leftv.size() && righindex<rightv.size())
    {
        if(leftv[leftindex] <= rightv[righindex])
        {
            v[mergeindex] = leftv[leftindex];
            leftindex++;
        }
        else{
            v[mergeindex] = rightv[righindex];
            righindex++;;
        }
        mergeindex++;
    }

    //copy remaining elements
    //leftv remaining data
    while(leftindex < leftv.size())
    {
        v[mergeindex] = leftv[leftindex];
        leftindex++;
        mergeindex++;
    }

    //right remaining data
    while(righindex < rightv.size())
    {
        v[mergeindex] = rightv[righindex];
        righindex++;
        mergeindex++;
    }

}

void mymergeSort(vector<int> v,int mybegin,int myend)
{
    cout<<"2"<<endl;
    if(mybegin >= myend){
        return;
    }

    int mid = (myend + mybegin)/2;
    mymergeSort(v, mybegin, mid);
    mymergeSort(v, mid + 1, myend);
    myMerge(v,mybegin, mid, myend);
}

int main(){
    cout<<"3"<<endl;
    vector<int> v = {8,6,7,3,1,23};
    mymergeSort(v,0,6);
    cout<<"4"<<endl;
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }

return 0;

}
