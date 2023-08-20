class Solution {
public:

    bool memoization(string s1, string s2, string s3,int i,int j,int k,vector<vector<int>>& dp)
    {
        if(i==s1.length() && j==s2.length() && k==s3.length())
        {
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        bool x=false;
        bool y=false;
        if(i!=s1.length())
        {
            if(s1[i]==s3[k])
            {
               x=memoization(s1,s2,s3,i+1,j,k+1,dp); 
            }
        }
        if(j!=s2.length())
        {
            if(s2[j]==s3[k])
            {
                y=memoization(s1,s2,s3,i,j+1,k+1,dp);
            }
        }
        return dp[i][j]=x || y;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return memoization(s1,s2,s3,0,0,0,dp);
    }
};