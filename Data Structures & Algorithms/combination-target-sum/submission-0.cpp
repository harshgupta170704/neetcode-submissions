class Solution {
private:
    void fun(vector<vector<int>>& ans,vector<int>&nums,int index,int target,vector<int>&cur)
    {
        if (target == 0) {
        ans.push_back(cur);
         return;
     }


      if (index == nums.size()) return;

        if(target>=nums[index]){
        cur.push_back(nums[index]);
        
        fun(ans,nums,index,target-nums[index],cur);
        cur.pop_back();
        
        }

        fun(ans,nums,index+1,target,cur);
        

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>cur;
        fun(ans,nums,0,target,cur);
        return ans;
    }
};
