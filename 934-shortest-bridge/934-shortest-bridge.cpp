class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q){
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j] != 1)
            return  ;
        
        grid[i][j] = 2 ;
        q.push({i,j}) ;
        
        dfs(i+1, j, grid, q) ;
        dfs(i-1, j, grid, q) ;
        dfs(i, j+1, grid, q) ;
        dfs(i, j-1, grid, q) ;
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), flag=0 ;
        queue<pair<int,int>> q ;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q) ;
                    flag=1 ;
                    break ;
                }
            }
            if(flag==1)
                break ;
        }
        
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<grid[i][j]<<" " ;
        //     }
        //     cout<<endl ;
        // }
        
        int dist =0 ;
        while(!q.empty()){
            int size = q.size() ;
            dist++ ;
            
            for(int i=0; i<size; i++){
                int x= q.front().first ;
                int y= q.front().second ;
                q.pop() ;
                
                //in range
                    // if not vis 
                        // grid val == 1    retrun dist-1 
                        // grid val == 0    push in stack
                
                if(x+1<n){
                    if(grid[x+1][y] != 2){
                        if(grid[x+1][y] == 1){
                            return dist-1 ; 
                        }
                        else if(grid[x+1][y] == 0){
                            q.push({x+1, y}) ;
                            grid[x+1][y] =2 ;
                        }
                    }
                }
                if(x-1>=0){
                    if(grid[x-1][y] != 2){
                        if(grid[x-1][y] == 1){
                            return dist-1 ; 
                        }
                        else if(grid[x-1][y] == 0){
                            q.push({x-1, y}) ;
                            grid[x-1][y] =2 ;
                        }
                    }
                }
                if(y+1<n){
                    if(grid[x][y+1] != 2){
                        if(grid[x][y+1] == 1){
                            return dist-1 ; 
                        }
                        else if(grid[x][y+1] == 0){
                            q.push({x, y+1}) ;
                            grid[x][y+1] =2 ;
                        }
                    }
                }
                if(y-1>=0){
                    if(grid[x][y-1] != 2){
                        if(grid[x][y-1] == 1){
                            return dist-1 ; 
                        }
                        else if(grid[x][y-1] == 0){
                            q.push({x, y-1}) ;
                            grid[x][y-1] =2 ;
                        }
                    }
                }
            }
        }
        
        
        return 0 ;
    }
};