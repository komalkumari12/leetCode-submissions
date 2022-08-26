class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxCount = 0;
        
        for(int i=0; i<sentences.size(); i++){
            int count =1 ;
            for(int j=0; j<sentences[i].size(); j++){
                if(sentences[i][j] == ' ') count++ ;
            }
            maxCount = max(maxCount, count) ;
        }
        
        return maxCount ;
    }
};