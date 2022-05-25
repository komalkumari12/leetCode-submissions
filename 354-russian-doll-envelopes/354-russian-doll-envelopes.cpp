class Solution {
public:
    static bool my_comp(vector<int> &a, vector<int> &b){
        if (a[0] == b[0]) {
            return (a[1] > b[1]);
        }
        return a[0] < b[0];
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       
        sort(envelopes.begin(), envelopes.end(), my_comp);

        vector<int> v;
        
        v.push_back(envelopes[0][1]);
        for (int i = 1; i < envelopes.size(); i++){
            int curr = envelopes[i][1];
            if (v.back() < curr)
                v.push_back(curr);
            else 
            {
                int idx = lower_bound(v.begin(), v.end(), curr) - v.begin();
                v[idx] = curr;
            }
        }
        return v.size();
    }
};