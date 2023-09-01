class Solution {
public:

    void dfs(vector<vector<int>>& ans, int delrow[], int delcol[], int r, int c, int color, int initial,vector<vector<int>>& image)
    {
        ans[r][c]=color;
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
            {
                if(image[nrow][ncol]==initial && ans[nrow][ncol]!=color)
                {
                    dfs(ans,delrow,delcol,nrow,ncol,color,initial,image);
                }
            }
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int initial=ans[sr][sc];
        dfs(ans,delrow,delcol,sr,sc,color,initial,image);
        return ans;
    }
};