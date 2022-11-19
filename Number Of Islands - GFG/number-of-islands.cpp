//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjoinSet{
    vector<int> parent, rank, size ;
    public:
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
    bool inRange(int row, int col, int n, int m){
        if(row>=0 && row<n && col>=0 && col<m)
            return true ;
        return false ;
    }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjoinSet ds(n*m) ;
        
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        vector<int> ans ;
        int count =0 ;

        for(auto it: operators){
            int row = it[0] ;
            int col = it[1] ;
            
            if(vis[row][col] == 1){
                ans.push_back(count) ;
                continue ;
            }
            
            vis[row][col] = 1 ;
            count++ ;
            
            int dr[] = {-1, 0, 1, 0} ;
            int dc[] = {0, 1, 0, -1} ;
            
            for(int ind =0 ; ind<4; ind++){
                int adjRow = row + dr[ind] ; 
                int adjCol = col + dc[ind] ; 
                
                if(inRange(adjRow, adjCol, n, m)){
                    if(vis[adjRow][adjCol] == 1){
                        int node = row * m + col ;
                        int adjNode = adjRow * m + adjCol ;
                        
                        if(ds.findParent(node) != ds.findParent(adjNode)){
                            count-- ;
                            ds.unionBySize(node, adjNode) ;
                        }
                    }
                }
            }
            
            ans.push_back(count) ;
        }
        
        return ans ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends