class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int n=a.size();
        set<char>s;
        int maxsize=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(s.find(a[i])==s.end())
            {
                s.insert(a[i]);
                int h=s.size();
                maxsize=max(maxsize,h);
            }
            else 
            {
              while(start!=i)
              {
                s.erase(a[start]);
                start++;
                if(s.find(a[i])==s.end()) break;
              }
               s.insert(a[i]); 
          
            }
          
        }
        return maxsize;

        }
        
};
