class Solution {
public:

    
    int tabulation(string text1,string text2)
    {
        int m=text1.length();
        int n=text2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
                else if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    /*int solve(string text1, string text2, int i,int j, vector<vector<int>>& dp)
    {
        if(i==0 || j==0)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i-1]==text2[j-1])
        {
            return dp[i][j]=1+solve(text1,text2,i-1,j-1,dp);
        }
        return dp[i][j]=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
    }*/

    int longestCommonSubsequence(string text1, string text2) {
        //int m=text1.length();
        //int n=text2.length();
        /*vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(text1,text2,m,n,dp); */
        return tabulation(text1,text2);
    }
};