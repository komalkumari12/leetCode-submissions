class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= 9; ++i) q.push(i);

        while (--n) {
            int q_size = size(q);
            while (q_size--) {
                const int val = q.front(); q.pop();
                const int prev = val % 10;
                
                if (prev - k >= 0) q.push(val * 10 + prev - k);
                
                if (k && prev + k <= 9) q.push(val * 10 + prev + k);
            }
        }

        vector<int> ans;
        ans.reserve(size(q));
        
        while (!empty(q)) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};