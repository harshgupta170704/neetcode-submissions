class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> m;
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int complement = target - numbers[i];

            if (m.find(complement) != m.end()) {
                return {m[complement], i + 1};
            }

            m[numbers[i]] = i + 1;
        }

        return {};
    }
};