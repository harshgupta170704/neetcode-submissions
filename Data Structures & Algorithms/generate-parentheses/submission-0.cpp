class Solution {
public:
   void fun(int n,int open,int closed,string &s,vector<string>& ans)
   {
      if(s.size()==2*n) {ans.push_back(s); return;}
      if(open>0)
      {
        s.push_back('(') ;
      fun(n,open-1,closed,s,ans);
      s.pop_back();
      }
      if(open<closed) 
      {
      s.push_back(')') ;
      fun(n,open,closed-1,s,ans);
      s.pop_back();
      } 

   }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open=n;
        int closed=n;
        string s;
        fun(n,open,closed,s,ans);
        return ans;
    }
};
