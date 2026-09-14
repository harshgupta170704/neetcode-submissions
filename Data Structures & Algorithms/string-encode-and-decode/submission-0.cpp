class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (string s : strs) {
            result += to_string(s.size()) + "#" + s;
        }

        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find '#'
            while (s[j] != '#') {
                j++;
            }

            // Get length of string
            int length = stoi(s.substr(i, j - i));

            // Move j after '#'
            j++;

            // Extract actual string
            string word = s.substr(j, length);

            result.push_back(word);

            // Move i to next encoded string
            i = j + length;
        }

        return result;
    }
};