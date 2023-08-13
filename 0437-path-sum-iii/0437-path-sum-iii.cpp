/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void solve(TreeNode* root, int targetSum, long sum, unordered_map<long,int>& m, int& count)
    {
        if(root==NULL)
        {
            return;
        }
        sum+=root->val;
        if(m.find(sum-targetSum)!=m.end())
        {
            count+=m[sum-targetSum];
        }
        m[sum]++;
        solve(root->left,targetSum,sum,m,count);
        solve(root->right,targetSum,sum,m,count);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)
        {
            return 0;
        }
        unordered_map<long,int>m;
        m[0]=1;
        long sum=0;
        int count=0;
        solve(root,targetSum,sum,m,count);
        return count;
    }
};