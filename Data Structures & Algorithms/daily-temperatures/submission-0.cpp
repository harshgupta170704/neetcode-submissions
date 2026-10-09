class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& v) {
      stack<int>st;
      vector<int>ans(v.size(),0);
      for(int i=0;i<v.size();i++)
      {
        while(!st.empty()&&v[i]>v[st.top()])
        {
          int index = st.top();
          st.pop();
          ans[index]=i-index;
        }
        st.push(i);
      }
      return ans;




    }
};
