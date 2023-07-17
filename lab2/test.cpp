#include<iostream>
#include<vector>
using namespace std;



int main(){
    vector<int> rightv  = {1,2,3,4,5,6,7,8};
    int mid = 4;
vector<int> leftv = {rightv.begin(),rightv.begin() + mid};
for(int i=0;i<leftv.size();i++){
    cout<<leftv[i];
}
return 0;

}
