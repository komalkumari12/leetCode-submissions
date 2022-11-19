//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjoinSet{
    public:
        vector<int> parent, rank, size ;
        DisjoinSet(int n){
            parent.resize(n+1) ;
            rank.resize(n+1, 0) ;
            size.resize(n+1, 1) ;
            
            for(int i=0; i<n+1; i++)
                parent[i] = i ;
        }
        
        int findParent(int node){
            if(parent[node] == node)
                return node ;
            return parent[node] = findParent(parent[node]) ;
        }
        
        void unionByRank(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(rank[par_v] < rank[par_u]){
                parent[par_v] = par_u ;
            }
            else if(rank[par_v] > rank[par_u]){
                parent[par_u] = par_v ;
            }
            else{
                parent[par_v] = par_u ;
                rank[par_u]++ ;
            }
        }
        
        void unionBySize(int u, int v){
            int par_u = findParent(u) ;
            int par_v = findParent(v) ;
            
            if(par_u == par_v)  return ;
            if(size[par_u] < size[par_v]){
                parent[par_u] = par_v ;
                size[par_v] += size[par_u] ;
            }
            else{
                parent[par_v] = par_u ;
                size[par_u] += size[par_v] ;
            }
        }
};

class Solution {
    bool inRange(int i ,int j, int n){
        if(i>=0 && j>=0 && i<n && j<n)
            return true ;
        return false ;
    }
    
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size() ;
        DisjoinSet ds(n*n) ;
        
        //Step 1
        for(int i=0; i<n; i++){
            for(int j=0; j<n ;j++){
                if(grid[i][j] == 1){
                    int dr[] = {0, -1, 0, 1} ;
                    int dc[] = {-1, 0, 1, 0} ;
                    
                    for(int ind =0; ind<4; ind++){
                        int new_row = i + dr[ind] ;
                        int new_col = j + dc[ind] ;
                        
                        if(inRange(new_row, new_col, n) && grid[new_row][new_col] == 1){
                            int node = i*n + j ;
                            int adjNode = new_row*n + new_col ;
                            
                            ds.unionBySize(node, adjNode) ;
                        }
                    }
                }
            }
        }
        
        //Step 2
        int maxSize = INT_MIN ;
        for(int i=0; i<n; i++){
            for(int j=0; j<n ;j++){
                if(grid[i][j] == 0){
                    set<int> st ;
                    int dr[] = {0, -1, 0, 1} ;
                    int dc[] = {-1, 0, 1, 0} ;
                    
                    for(int ind =0; ind<4; ind++){
                        int new_row = i + dr[ind] ;
                        int new_col = j + dc[ind] ;
                        
                        if(inRange(new_row, new_col, n) && grid[new_row][new_col] == 1){
                            int adjNode = new_row*n + new_col ;
                            st.insert(ds.findParent(adjNode)) ;
                        }
                    }
                    
                    int currSize = 0 ;
                    for(auto it: st){
                        currSize += ds.size[ds.findParent(it)] ;
                    }
                    maxSize = max(maxSize, 1 + currSize) ;
                }
            }
        }
        
        for(int i=0; i<n*n; i++){
            maxSize = max(maxSize, ds.size[ds.findParent(i)]) ;
        }
        
        return maxSize ;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends