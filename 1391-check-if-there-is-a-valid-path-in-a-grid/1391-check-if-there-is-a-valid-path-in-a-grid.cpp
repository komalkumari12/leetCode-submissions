class Solution {
    bool inRange(int i, int j, int n, int m){
        if(i>=0 && j>=0 && i<n && j<m)
            return true ;
        return false ; 
    }

    bool checkForPath(int i, int j, int n, int m, vector<vector<int>>& vis, vector<vector<int>>& grid){
        queue<pair<int,int>> q ;
        q.push({i, j}) ;
        
        while(!q.empty()){
            int row = q.front().first ;
            int col = q.front().second ;
            q.pop() ;
            vis[row][col] = 1 ;
            
            if(row == n-1  &&  col == m-1)  return true ;
            
            if(grid[row][col] == 1){
                if(inRange(row, col-1, n, m) && !vis[row][col-1] && (grid[row][col-1] == 1  ||  grid[row][col-1] == 4  || grid[row][col-1] == 6))
                    q.push({row, col-1}) ;
                
                if(inRange(row, col+1, n, m) && !vis[row][col+1] && (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5))
                    q.push({row, col+1}) ;
                
            }
                   
            if(grid[row][col] == 2){
                if(inRange(row-1, col, n, m) && !vis[row-1][col] && (grid[row-1][col] == 2  ||  grid[row-1][col] == 3  || grid[row-1][col] == 4))
                    q.push({row-1, col}) ;
                
                if(inRange(row+1, col, n, m) && !vis[row+1][col] && (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6))
                    q.push({row+1, col}) ;
                
            }
                   
            if(grid[row][col] == 3){
                if(inRange(row, col-1, n, m) && !vis[row][col-1] && (grid[row][col-1] == 1  ||  grid[row][col-1] == 4  || grid[row][col-1] == 6))
                    q.push({row, col-1}) ;
                
                if(inRange(row+1, col, n, m) && !vis[row+1][col] && (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6))
                    q.push({row+1, col}) ;
            }
                
            if(grid[row][col] == 4){
                if(inRange(row, col+1, n, m) && !vis[row][col+1] && (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5))
                    q.push({row, col+1}) ;
                
                if(inRange(row+1, col, n, m) && !vis[row+1][col] && (grid[row+1][col] == 2  ||  grid[row+1][col] == 5  || grid[row+1][col] == 6))
                    q.push({row+1, col}) ;
                
            }
                
            if(grid[row][col] == 5){
                if(inRange(row, col-1, n, m) && !vis[row][col-1] && (grid[row][col-1] == 1  ||  grid[row][col-1] == 4  || grid[row][col-1] == 6))
                    q.push({row, col-1}) ;
                
                if(inRange(row-1, col, n, m) && !vis[row-1][col] && (grid[row-1][col] == 2  ||  grid[row-1][col] == 3  || grid[row-1][col] == 4))
                    q.push({row-1, col}) ;
                
            }
                
            if(grid[row][col] == 6){
                if(inRange(row-1, col, n, m) && !vis[row-1][col] && (grid[row-1][col] == 2  ||  grid[row-1][col] == 3  || grid[row-1][col] == 4))
                    q.push({row-1, col}) ;
                
                if(inRange(row, col+1, n, m) && !vis[row][col+1] && (grid[row][col+1] == 1  ||  grid[row][col+1] == 3  || grid[row][col+1] == 5))
                    q.push({row, col+1}) ;
            }
            
        }
        
        return false ;
    }
    
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size() ;
        vector<vector<int>> vis(n, vector<int>(m, 0)) ;
        
        if(checkForPath(0, 0, n, m, vis, grid))
            return true ;
        return false ;
    }
};