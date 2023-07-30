class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        vector<pair<int,int>>index;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    index.push_back({i,j});
                }
            }
        }

        for(auto k:index)
        {
            for(int r=0;r<m;r++)
            {
                matrix[k.first][r]=0;
            }
            for(int c=0;c<n;c++)
            {
                matrix[c][k.second]=0;
            }
        }
    }
};