#include<bits/stdc++.h>
using namespace std;


const int N=5003;
int visited[N]={0};

void dfs(vector<int> adj[],int src){
    visited[src]=1;
    cout<<src<<" ";
    for(auto it:adj[src]){
        if(!visited[it]){
            dfs(adj,it);
            //cout<<it<<" ";
        }
    }
}


int main(){
    int n,e;
    cin>>n>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(adj,0);

    
}
