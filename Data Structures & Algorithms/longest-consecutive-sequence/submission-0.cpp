class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> st;

        // Put all numbers in set
        for (int num : nums) {
            st.insert(num);
        }

        int ans = 0;

        for (int num : nums) {

            // Check if num is the starting number
            if (st.find(num - 1) == st.end()) {

                int length = 1;
                int current = num;

                // Check next numbers
                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }

        return ans;
    }
};