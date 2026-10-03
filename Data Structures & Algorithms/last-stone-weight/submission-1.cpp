class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>p; //max
        int n=stones.size();
        if(n==1) return stones[0];
        for(int i=0;i<n;i++)
        {
           p.push(stones[i]);
        }
        while(p.size()>1)
        {
            int x=p.top();
            p.pop();
            int y=p.top();
            p.pop();
            if(x>=y) p.push(x-y);
            
        }
        return p.top();
    }
};
