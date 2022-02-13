 class Solution {
 public:
     int orangesRotting(vector<vector<int>>& grid) {
         if(grid.empty()) return 0 ;
         int minutes=0 , tot=0,count=0 ; 
         queue<pair<int,int>> rotten ;
        
         for(int i=0 ;i<grid.size() ;i++){
             for(int j= 0; j<grid[0].size() ;j++){
                 if(grid[i][j] != 0) tot++;
                 if(grid[i][j] == 2) rotten.push({i,j}) ;
             }
         }
        
         int dx[4] = {0, 0, 1, -1};
         int dy[4] = {1, -1, 0, 0};
        
         while(!rotten.empty()){
             int size = rotten.size() ;
             count += size ;
            
             while(size--){
                 int x = rotten.front().first ;
                 int y = rotten.front().second ;
                    rotten.pop() ;
                
                 for(int i= 0;i<4 ;i++){
                     int newx =x + dx[i];
                     int newy =y + dy[i] ;
                    
                     if(newx<0 || newy<0 || newx>=grid.size() || newy>=grid[0].size() || grid[newx][newy] != 1) continue ;
                     grid[newx][newy] = 2 ;
                     rotten.push({newx,newy}) ;
                 }
             }
             if(!rotten.empty()) minutes++ ;
         }
            
         return tot == count ? minutes : -1 ;
     }
 };

