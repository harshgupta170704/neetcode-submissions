
class Solution {
public:
    int characterReplacement(string a, int k) {
        int n = a.size();
        map<char, int> m;

        int start = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            m[a[i]]++;

            int maxi = 0;

            for (auto &x : m) {
                maxi = max(maxi, x.second);
            }

            while ((i - start + 1) - maxi > k) {
                m[a[start]]--;
                start++;
            }

            ans = max(ans, i - start + 1);
        }

        return ans;
    }
};
