class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>map_ans;
        vector<vector<string>>ans;
        for(auto &s:strs)
        {
            string m=s;
            sort(m.begin(),m.end());
            map_ans[m].push_back(s);
        }
        for(auto it:map_ans)
        {
            ans.push_back(it.second);
        }
        return ans;


    }
};
