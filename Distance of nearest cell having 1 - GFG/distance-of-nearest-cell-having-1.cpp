//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    private :
        int dx[4] = {1, 0, -1, 0} ;
        int dy[4] = {0, -1, 0, 1} ;
        
        bool inRange(int i, int j, int n, int m){
            if(i<n && j<m && i>=0 && j>=0)  return true ;
            return false ;
        }
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n = grid.size(); 
	    int m = grid[0].size() ;
	    queue<pair<int, int>> q ;
	    
	    for(int i=0; i<n; i++){
	        for(int j=0; j<m; j++){
	            if(grid[i][j] == 1){
	                q.push({i, j}) ;
	                grid[i][j] = 0 ;
	               // cout<<i<<" "<<j<<endl ;
	            }
	            else{
	                grid[i][j] = -1 ;
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int size = q.size() ;
	        
	        for(int i=0; i<size; i++){
	            int row = q.front().first ;
	            int col = q.front().second ;
	            int parDist = grid[row][col] ;
	            q.pop() ;
	            
	            
	            for(int k = 0; k<4; k++){
	                int new_row = row + dx[k] ;
	                int new_col = col + dy[k] ;
	                
	                if(inRange(new_row, new_col, n, m) && grid[new_row][new_col] == -1){
	                    q.push({new_row, new_col}) ;
	                    grid[new_row][new_col] = parDist+1 ;
	                }
	            }
	        }
	    }
	    
	    return grid ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends