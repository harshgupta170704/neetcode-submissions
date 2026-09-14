class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count0=0;
        int product=1;
        int n=nums.size();
       for(int i=0;i<n;i++)
       {
         if(nums[i]==0)count0 ++;
         if(nums[i]!=0)
         product=product*nums[i];
       }
       vector<int>ans(n,0);
       if(count0>1) return ans;
       if(count0==0) 
       {
        for(int i=0;i<n;i++)
        {
            ans[i]=product/nums[i];
        }
        return ans;
       }
       
       for(int i=0;i<n;i++)
       {
          if(nums[i]!=0) ans[i]=0;
          if(nums[i]==0) ans[i]=product;
       }
       return ans;


    }
};
