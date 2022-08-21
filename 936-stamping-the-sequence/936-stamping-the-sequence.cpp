class Solution {
public:
    bool canReplace(string& stamp, string& target, int i)
    {
        bool flag = false;
        
        for(int j=0;j<stamp.size();j++)
        {
            if(target[i+j] != '?') flag = true;
            if(stamp[j]!=target[i+j]  &&  target[i+j]!='?') 
                return false;
        }
        
        return flag;
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        
        vector<int> res;
        vector<int> vis(n,0);
        
        string s = "";
        for(int i=0;i<n;i++)
            s+="?"; 
        
        for(int k=0;k<n;k++)
        {
            bool change=false;
            for(int i=0;i<=n-m;i++)
            {
                if(vis[i]==0 && canReplace(stamp,target,i))
                {
                    for(int j=i;j<i+m;j++)
                        target[j]='?'; 
                    
                    vis[i]=1;
                    res.push_back(i);
                    change=true;
                }
            }
            if(target==s) 
                break;
            if(!change) return {}; 
        }
        reverse(res.begin(),res.end()); 
        if(target==s)
            return res;
        
        else return {};
    }
};