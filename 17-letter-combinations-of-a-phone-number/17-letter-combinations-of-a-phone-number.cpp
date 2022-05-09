class Solution {
private:
    vector<string> res;
    vector<string> mpp = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
public:
    void backtrack(string digits, int idx, string str)
    {
        if(idx == digits.size())
        {
            if(str.size() > 0) res.emplace_back(str);
            return;
        }
        
        for(char ch : mpp[digits[idx] - '0'])
        {
            str += ch;
            backtrack(digits, idx + 1, str);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        backtrack(digits, 0, "");
        return res;
    }
};