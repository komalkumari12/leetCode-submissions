//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
    
        // int n = edges.size() ;
        vector<vector<int>> dist(n,vector<int>(n, 1e9)) ;
        
        for(auto it: edges){
            int u = it[0] ;
            int v = it[1] ;
            int wt = it[2] ;
            
            dist[u][v] = wt ;
            dist[v][u] = wt ;
        }
        
        for(int i=0; i<n; i++){
            dist[i][i] = 0 ;
        }
                     
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]) ;
                }
            }
        }   
        
        int minCount = INT_MAX ;
        int ans = -1 ;
        
        for(int i=0; i<n; i++){
            int count =0 ;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold){
                    count++ ;
                }
            }
            
            if(count  <= minCount){
                minCount = count ;
                ans = i ;
            }
        }
        
        
        return ans ;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends