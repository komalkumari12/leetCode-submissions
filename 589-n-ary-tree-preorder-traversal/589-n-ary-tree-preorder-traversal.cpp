class Solution {
    vector<int> ans;
    
    public:
    vector<int> preorder(Node* root) {
    
        if(root)
        {
            ans.push_back(root->val);
        for(auto it : root->children){
            preorder(it);
        }
        }
        return ans;
    }
};