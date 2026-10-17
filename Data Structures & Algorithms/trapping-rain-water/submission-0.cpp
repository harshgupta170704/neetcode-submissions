class Solution {
public:
    int trap(vector<int>& h) {
         int leftMax = 0, rightMax = 0;
int water = 0;
int lo=0;
int hi=h.size()-1;
while (lo < hi) {
    if (h[lo] <= h[hi]) {
        leftMax = max(leftMax, h[lo]);
        water += leftMax - h[lo];
        lo++;
    } else {
        rightMax = max(rightMax, h[hi]);
        water += rightMax - h[hi];
        hi--;
    }
}

return water;
    }
};
