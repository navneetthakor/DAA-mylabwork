#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void fillData(vector<vector<int>> &gp, queue<int> &q, vector<int> &visited, int index){
    for(int i=0; i<gp[index].size(); i++){
        int n = gp[index][i], flag = 0;
        for(int j=0; j<visited.size(); j++){
            if(visited[j] == n){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            visited.push_back(n);
            q.push(n);
        }
    }
}

void popData(vector<vector<int>> &gp, queue<int> &q, vector<int> &visited){
    while (!q.empty())
    {
        int index = q.front();
        q.pop();
        cout<<index<<endl;
        fillData(gp,q,visited,index);
    }
    
}
void bfs(vector<vector<int>> &gp){
    queue<int> q;
    vector<int> visited;
    visited.push_back(0);
    q.push(0);
    popData(gp,q,visited);

    cout<<"Following is the visited nodes in graph : "<<endl;
    for(int i=0; i<visited.size(); i++){
        cout<<visited[i]<< " ";
    }
    cout<<"BFS completed!!!!!!!"<<endl;
}

int main(){
    // creating graph
    int nodes,tempj, temp;
    vector<vector<int>> gp;
    vector<int> tempv;
    cout<<"Enter the number of nodes : "<<endl;
    cin>>nodes;

    //taking graph data from user;
    for(int i=0; i<nodes; i++){
        cout<<"For node : "<<i<<endl;
        cout<<"Enter no of connected nodes : ";
        cin>>tempj;

        for(int j=0; j<tempj; j++){
            cin>>temp;
            tempv.push_back(temp);
        }
        gp.push_back(tempv);
        tempv.clear();
    }

    // calling bfs
    bfs(gp);



    return 0;
}