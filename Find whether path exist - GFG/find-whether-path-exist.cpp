//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{   bool inRange(int i, int j, int n){
        if(i>=0 && j>=0 && i<n && j<n)
            return true ;
        return false ;        
    }
    

    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int n = grid.size() ;
        queue<pair<int,int>> q ;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({i, j}) ;
                }
            }
        }
        
        int dx[4] = {0, 1, 0, -1} ;
        int dy[4] = {1, 0, -1, 0} ;
        while(!q.empty()){
            int i = q.front().first ;
            int j = q.front().second ;
            q.pop() ;
            
            // if(grid[i][j] == 2)
            //     return true ;
            
            for(int k=0; k<4; k++){
                int new_r = i + dx[k] ;
                int new_c = j + dy[k] ;
                
                if(inRange(new_r, new_c, n)){
                    if(grid[new_r][new_c] == 2)
                        return true ;
                    
                    if(grid[new_r][new_c] == 3){
                        grid[new_r][new_c] = 4 ;
                        q.push({new_r, new_c}) ;
                    }        
                }
            }
            
        }
        
        return false ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends