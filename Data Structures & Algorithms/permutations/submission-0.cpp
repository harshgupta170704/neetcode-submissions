class Solution {
public:
    void fun(vector<int>& nums,vector<vector<int>>&ans,set<int>&s,vector<int>&cur,int index)
    {
       if(cur.size()==nums.size()) {ans.push_back(cur);}
       for(int i=0;i<nums.size();i++)
       {
          if(s.find(nums[i])==s.end()) 
          {
            s.insert(nums[i]);
            cur.push_back(nums[i]);
            fun(nums,ans,s,cur,i+1);
            s.erase(nums[i]);
            cur.pop_back();
          }

       }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        set<int>s;
        vector<int>cur;

        fun(nums,ans,s,cur,0);
        return ans;

    }
};
