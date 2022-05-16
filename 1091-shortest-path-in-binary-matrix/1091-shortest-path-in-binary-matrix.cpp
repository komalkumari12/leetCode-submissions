class Solution {
public:
    
    bool inBounds(vector<vector<int>>& grid, int i, int j, int n, vector<vector<int>>& visited){
        return (i>=0 && i<n && j>=0 && j<n && grid[i][j]==0 && !visited[i][j]);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int> (n, 0));
        queue<pair<int, int>> q;
        int ans = 0;
        
        if(grid[0][0] == 0){
            q.push({0, 0});
            visited[0][0] = true;
        }
                
        while(!q.empty()){
            int size = q.size();
            ans++;
            
            for(int i = 0; i < size; i++){
                pair<int, int> frontNode = q.front();
                q.pop();
            
                int r = frontNode.first, c = frontNode.second;

                if(c==n-1 and r==n-1) return ans;

                for(int k = r - 1; k <= r + 1 ; k++){
                    for(int l = c - 1; l <= c + 1; l++){
                        if(inBounds(grid, k, l, n, visited)){
                            q.push({k, l});
                            visited[k][l] = true;
                        }
                    }
                }                
            }            
            
        } 
        return -1;
    }
};