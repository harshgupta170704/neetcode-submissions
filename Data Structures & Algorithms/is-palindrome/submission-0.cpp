class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        while(i < j)
        {
            // Skip non-alphanumeric characters from left
            if(!((s[i] >= 'A' && s[i] <= 'Z') ||
                 (s[i] >= 'a' && s[i] <= 'z') ||
                 (s[i] >= '0' && s[i] <= '9')))
            {
                i++;
                continue;
            }

            // Skip non-alphanumeric characters from right
            if(!((s[j] >= 'A' && s[j] <= 'Z') ||
                 (s[j] >= 'a' && s[j] <= 'z') ||
                 (s[j] >= '0' && s[j] <= '9')))
            {
                j--;
                continue;
            }

            // Convert lowercase to uppercase
            if(s[i] >= 'a' && s[i] <= 'z')
                s[i] -= 32;

            if(s[j] >= 'a' && s[j] <= 'z')
                s[j] -= 32;

            // Compare
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
};