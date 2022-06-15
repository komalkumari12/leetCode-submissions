class Solution {
public:
    bool check(string a,string b){
        int count = 0;
        int index = 0;
        for(int i = 0 ; i < a.size() and index < b.size(); i++,index++){
            if(a[i] != b[index]){
                count++;
                i--;
            }
            if(count > 1) return false;
        }
        return count <= 1;
    }
    static bool comp(string a, string b){
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int ans = 1;
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),comp);
        for(int i = 0 ; i < words.size() ; i++)
            for(int j = i - 1 ; j >= 0 and words[j].size() + 1 >= words[i].size() ; j--)
                if(words[j].size() == words[i].size() - 1)
                    if(check(words[j],words[i]))
                        dp[i] = max(dp[j] + 1,dp[i]);
        for(int i = 0 ; i < words.size() ; i++)
            ans = max(ans,dp[i]);
        return ans;
    }
};