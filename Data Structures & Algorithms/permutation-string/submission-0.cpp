class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       vector<int>a(26,0);
       for(int i=0;i<s1.size();i++)
       {
          a[s1[i]-'a']++;
       }  
       int m=s2.size();
       int n=s1.size();
       if(m<n) return false;
       vector<int>freq(26,0);
       for(int i=0;i<n;i++)
       {
           freq[s2[i]-'a']++;
       }
       if(freq==a) return true;
       int start=0;
       for(int i=n;i<m;i++)
       {
          freq[s2[start] - 'a']--;;
          start++;
          freq[s2[i] - 'a']++;
          if(freq==a) return true;

       }
       return false;
    }
};
