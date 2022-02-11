class Solution {
public:
    void colorHelp( vector<vector<int>>&image ,int i ,int j ,int color ,int newColor){
        if(i<0  ||   j<0  ||  i >= image.size()  ||  j >= image[0].size()  ||  image[i][j] != color) return  ;
        
        image[i][j] = newColor ;
        
        colorHelp(image , i+1 ,j ,color ,newColor) ;
        colorHelp(image , i-1 ,j ,color ,newColor) ;
        colorHelp(image , i ,j+1 ,color ,newColor) ;
        colorHelp(image , i ,j-1 ,color ,newColor) ;
    }
        
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color =image[sr][sc] ;
        
        if(color != newColor)
        colorHelp(image, sr, sc, color , newColor) ;
        
        return image ;
    }
};