class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int count=0;
        for(auto& row:grid)
        {
            int left=0;
            int right=row.size()-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(row[mid]<0)
                {
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            count+=(grid[0].size()-left);
        }
        return count;
    }
};