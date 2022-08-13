class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length(), wlen = words[0].length(), m = words.size();
        int tot = m*wlen;   //length of the window
        
        vector<int> ans;
        
        unordered_map<string, int> mpp;
        for(auto it : words)                 //store the words in a map
            mpp[it]++;
        
        for(int i=0;i<=n-tot; i++){
            unordered_map<string,int> cur;  //make a map for the words of the current window
            
            for(int j=i; j<i+tot; j+=wlen){ //add the words to the map
                string w = "";
                for(int k=j; k<j+wlen; k++){
                    w+=s[k];
                }
                cur[w]++;
            }
            if(cur==mpp) ans.push_back(i);   //compare both maps
        }
        return ans;
    }
};