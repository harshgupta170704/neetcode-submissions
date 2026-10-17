class Solution {
public:
    int maxArea(vector<int>& h) {
        int lo=0;
        int hi=h.size()-1;
        int maxi=0;
        while(lo<hi)
        {
            if(h[lo]<=h[hi]) 
            {
              maxi=max(h[lo]*(hi-lo),maxi);
              lo++;
            }
            else 
            {
               maxi=max((h[hi])*(hi-lo),maxi);
              hi--; 
            }
        }
        return maxi;
    }
};
