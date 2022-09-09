class Solution {
public:
    static bool cmp(vector<int>&v1,vector<int>&v2)
    {
        return v1[0]==v2[0] ? v1[1]>v2[1] : v1[0]<v2[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& nums)
    {
        int count=0;
        stack<pair<int,int>> st;
        
        sort(nums.begin(),nums.end(),cmp);
        
        for(int i=0; i<nums.size(); i++)
        {
            while(st.size() && st.top().first<nums[i][0] && st.top().second<nums[i][1])
            {
                st.pop();
                count++;
            }
            st.push({nums[i][0],nums[i][1]});
        }
        
        return count;
    }
};