class Solution {
private:
    void fun(vector<vector<int>>& ans,
             vector<int>& nums,
             int index,
             int target,
             vector<int>& cur) {

        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        if (index == nums.size() || target < 0)
            return;

        // TAKE
        if (nums[index] <= target) {
            cur.push_back(nums[index]);

            fun(ans, nums, index + 1,
                target - nums[index], cur);

            cur.pop_back();
        }

        // DON'T TAKE
        int next = index + 1;

        // Skip duplicate values
        while (next < nums.size() &&
               nums[next] == nums[index]) {
            next++;
        }

        fun(ans, nums, next, target, cur);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> cur;

        fun(ans, nums, 0, target, cur);

        return ans;
    }
};