class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target= 0-(nums[i]+nums[j]);
                auto it = lower_bound(nums.begin() + j + 1,
                      nums.end(), target);
                if( it!=nums.end() && *it==target) 
                {
                  ans.insert({nums[i],nums[j],*it});
                }
            }
        }
        vector<vector<int>>ansnew;
        for(auto & it : ans)
        {
            ansnew.push_back(it);
        }
        return ansnew;
    }
};
