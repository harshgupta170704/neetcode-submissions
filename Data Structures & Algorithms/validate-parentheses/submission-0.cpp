class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {

            if (s[i] == '[') {
                st.push(-3);
            }
            else if (s[i] == '{') {
                st.push(-2);
            }
            else if (s[i] == '(') {
                st.push(-1);
            }
            else {
                // Check if stack is empty
                if (st.empty()) return false;

                int x = st.top();
                st.pop();

                int y;

                if (s[i] == ']') {
                    y = 3;
                }
                else if (s[i] == '}') {
                    y = 2;
                }
                else {
                    y = 1;
                }

                if (x + y != 0) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};