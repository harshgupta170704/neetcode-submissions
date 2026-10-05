class Solution {
private:
   void fun(vector<int>& nums,vector<vector<int>>&ans,int index,vector<int> &current)
   {
     if(index == nums.size()) {
    ans.push_back(current);
    return;
}
    
     current.push_back(nums[index]);
    fun(nums, ans, index + 1, current);
    current.pop_back();
     fun(nums,ans,index+1,current);
     
   }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int> current;
         fun(nums,ans,0,current);
         return ans;
    }
};
