class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int j=-1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            if(matrix[i][m-1]>=target) 
            {
                j=i;
                break;
            }
        }
        if(j==-1) return false;
        if(matrix[j][0]>target) return false;
        int lo=0;
        int hi=m-1;
        while(hi-lo>1)
        {
            int mid=(hi+lo)/2;
            if(matrix[j][mid]<=target) lo=mid;
            else hi=mid-1;
        }
       
        if(matrix[j][lo]==target) return true;
        if(matrix[j][hi]==target) return true;
        else return false;
    }
};
