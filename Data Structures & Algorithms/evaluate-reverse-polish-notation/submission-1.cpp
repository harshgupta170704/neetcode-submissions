class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;
        int x;
        int y;
        for(int i=0;i<n;i++)
        {
            if(tokens[i]=="+")
            {
               x= st.top();
               st.pop();
               y= st.top();
               st.pop();
               st.push(x+y);
            }
            else if(tokens[i]=="-")
            {
               x= st.top();
               st.pop();
               y= st.top();
               st.pop();
               st.push(y-x);
            }
            
            else if(tokens[i]=="/")
            {
               x= st.top();
               st.pop();
               y= st.top();
               st.pop();
               st.push(y/x);
            }
            else if(tokens[i]=="*")
            {
               x= st.top();
               st.pop();
               y= st.top();
               st.pop();
               st.push(x*y);
            }
            else st.push(std::stoi(tokens[i]));
        }
        return st.top();
    }
};
