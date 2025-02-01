#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>> &adjs,vector<int> &visited){
    visited[node]=1;
    for(auto it:adjs[node]){
        if(!visited[it]){
            dfs(it,adjs,visited);
        }
    } 
}

int main() {
    int count=0;
    int V,E;
    cin>>V>>E;
    vector<int> visited(V,0);
    vector<vector<int>> adjs(V);
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    
        
    for(int i=0;i<V;i++){
        if(!visited[i]){
            count++;
            dfs(i,adjs,visited);
        }
    }
    cout<<count<<endl;
    return 0;
}