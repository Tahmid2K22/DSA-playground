#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[],int src,int n){
    vector<int> visited(n,0);
    queue<int> q;
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";
       
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[node]=1;
            }   
        }
    }
    cout<<endl;
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
    bfs(adj,0,n);

    
}