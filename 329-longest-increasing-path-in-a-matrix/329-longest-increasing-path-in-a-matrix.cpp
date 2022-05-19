class Solution {
public:
    int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){       
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]==-1) 
            return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=0,down=0,right=0,left=0;
        int a=matrix[i][j];
        
        matrix[i][j]=-1;
        if(i>0 && matrix[i-1][j]>a){
            up=1+f(i-1,j,matrix,dp);
        }
        if(j>0 && matrix[i][j-1]>a){
            left=1+f(i,j-1,matrix,dp);
        }
        if(j<matrix[0].size()-1 && matrix[i][j+1]>a){
            right=1+f(i,j+1,matrix,dp);
        }
        if(i<matrix.size()-1 && matrix[i+1][j]>a){
            down=1+f(i+1,j,matrix,dp);
        }
        matrix[i][j]=a;
        return dp[i][j]=max(up,max(left,max(right,down)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        int maxi=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi=max(maxi,f(i,j,matrix,dp)+1);
            }
        }
        return maxi;
    }
};