//https://www.geeksforgeeks.org/problems/find-the-number-of-islands/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    int dx[8]={1,-1,0,0,1,1,-1,-1};
    int dy[8]={0,0,1,-1,1,-1,1,-1};

    void dfs(int nodex,int nodey,vector<vector<char>>& grid,map<pair<int,int>,int> &visited,int n,int m){
        visited[{nodex,nodey}]=1;
        for(int i=0;i<8;i++){
            int x=nodex+dx[i];
            int y=nodey+dy[i];
            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1' && !visited[{x,y}]){
                dfs(x,y,grid,visited,n,m);
            }
        } 
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        map<pair<int,int>,int> visited;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[{i,j}]){
                    dfs(i,j,grid,visited,n,m);
                    count++;
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends