class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            
               m[nums[i]]++;

        }

        priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> minheap;
        for(auto &it:m)
        {
           int num = it.first;
           int freq = it.second;
           minheap.push({freq,num});
           if(minheap.size()>k) minheap.pop();
        }
         vector<int> ans;

        while (!minheap.empty()) {
            ans.push_back(minheap.top().second);
            minheap.pop();
        }

        return ans;
    }
};
