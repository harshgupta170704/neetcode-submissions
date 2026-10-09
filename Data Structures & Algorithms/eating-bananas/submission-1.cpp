class Solution {
public:
    bool fun(vector<int>& p, int h,int target)
    {
      int count=0;
      for(int i=0;i<p.size();i++)
      {
        count+=(p[i]+target-1)/target;
      }
      if(count>h) return false;
      else return true;
    }
public:
    int minEatingSpeed(vector<int>& p, int h) {
        sort(p.begin(),p.end());
        int lo = 1;
        int hi = p[p.size()-1];
        while(hi-lo>1)
        {
            int mid=(hi+lo)/2;
            if(fun(p,h,mid)==false)lo=mid+1;
            else hi=mid;
        }
         if(fun(p,h,lo)==true) return lo;
         else return hi;


        

    }
};
