
class Solution {
public:
    void fun(vector<int>& nums, set<vector<int>>& s,
             vector<int>& cur, int index) {

        if (index == nums.size()) {
            s.insert(cur);
            return;
        }

        // Include current element
        cur.push_back(nums[index]);
        fun(nums, s, cur, index + 1);

        // Backtrack
        cur.pop_back();

        // Exclude current element
        fun(nums, s, cur, index + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<vector<int>> s;
        vector<int> cur;

        fun(nums, s, cur, 0);

        return vector<vector<int>>(s.begin(), s.end());
    }
};
