#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//to display graph



//------------------------DFS related functions------------------------------------------------
void fillData(vector<vector<int>> &v,  stack<int> &unvisited, vector<int> &checkstack, int index){
    //fill the data in stack + chekcstack
    for(int i=0; i<v[index].size(); i++){
        int n = v[index][i], flag = 0;
        for(int j=0; j<checkstack.size();j++){
            if(checkstack[j]== n){
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            unvisited.push(n);
            checkstack.push_back(n);
        }
    }
}

//popdata to make stack empty
void popData(vector<vector<int>> &v,  stack<int> &unvisited, vector<int> &checkstack, vector<int> &visited){
    while(!unvisited.empty()){
        int n = unvisited.top();
        cout<<n<<endl;
        visited.push_back(n);
        unvisited.pop();
        fillData(v,unvisited,checkstack,n);
    }
}

void dfs(vector<vector<int>> &v){
//to actually implement the dfs
stack<int> unvisited;
vector<int> visited;
vector<int> checkstack;
fillData(v, unvisited, checkstack, 0);
popData(v, unvisited, checkstack,visited);

cout<<"visited data : "<<endl;
for(int i=0; i<visited.size(); i++){
    cout<<visited[i]<<" ";
}
cout<<"DFS completed!!!"<<endl;
}


//main function
int main(){

//to store graph as matrix representation
vector<vector<int>> v;
int nodes, tempj, temp;
cout<<"Enter the number of nodes : " ;
cin>>nodes;

vector<int> vt;
for(int i =0; i<nodes; i++){
        cout<<"Enter for node : "<<i<<endl;
        cout<<"Enter number of connected nodes: ";
        cin>>tempj;
    for(int j=0; j<tempj; j++){
       cin>>temp;
        vt.push_back(temp);
    }
    v.push_back(vt);
    vt.clear();
}

//call to dfs
dfs(v);




return 0;
}

