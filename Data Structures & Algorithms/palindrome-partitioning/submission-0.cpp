class Solution {
public:
    bool isPal(int i,int j,string &s)
    {
        if(i>=j) return true;
        if(s[i]==s[j]) return isPal(i+1,j-1,s);
        return false;
    }
    void func(int i,int n,string &s,vector<string> &k,vector<vector<string>> &ans)
    {
        if(i==n)
        {
            ans.push_back(k);
            return;
        }
        for(int j=i;j<n;j++)
        {
            if(isPal(i,j,s))
            {
                k.push_back(s.substr(i,j-i+1));
                func(j+1,n,s,k,ans);
                k.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> k;
        vector<vector<string>> ans;
        func(0,n,s,k,ans);
        return ans;
    }
};
