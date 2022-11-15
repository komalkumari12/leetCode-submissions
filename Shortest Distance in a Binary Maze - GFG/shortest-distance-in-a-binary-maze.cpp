//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size() ;
        
        int sx = source.first , dx = destination.first ;
        int sy = source.second , dy = destination.second ;
        grid[sx][sy] = 2 ;
        
        queue<pair<int,int>> q;
        q.push({sx, sy}) ;
        
        int level = 0 ;
        while(!q.empty()){
            int size = q.size() ;
            level++ ;
            
            for(int i=0; i<size; i++){
                int x1 = q.front().first ;
                int y1 = q.front().second ;
                q.pop() ;
                
                if(x1 == dx && y1 == dy)
                    return level-1 ;
            
                if(x1+1 < n && grid[x1+1][y1] == 1){
                    grid[x1+1][y1] = 2 ;
                    q.push({x1+1, y1}) ;
                }
                if(x1-1 >= 0 && grid[x1-1][y1] == 1){
                    grid[x1-1][y1] = 2 ;
                    q.push({x1-1, y1}) ;
                }
                if(y1+1 < m && grid[x1][y1+1] == 1){
                    grid[x1][y1+1] = 2 ;
                    q.push({x1, y1+1}) ;
                }
                if(y1-1 >= 0 && grid[x1][y1-1] == 1){
                    grid[x1][y1-1] = 2 ;
                    q.push({x1, y1-1}) ;
                }
            }
        }
        
        return -1 ;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends