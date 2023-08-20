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

    void solve(TreeNode* root,int &sum,int value)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            sum+=value*10+root->val;
            return;
        }
        value=value*10+root->val;
        solve(root->left,sum,value);
        solve(root->right,sum,value);
    }
    int sumNumbers(TreeNode* root) {
        vector<int>arr;
        if(root==NULL)
        {
            return 0;
        }
        int sum=0;
        int value=0;
        solve(root,sum,value);
        return sum;
    }
};