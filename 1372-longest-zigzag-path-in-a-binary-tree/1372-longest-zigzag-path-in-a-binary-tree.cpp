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

    void solve(TreeNode* root, int& maxi, int count,bool leftdir)
    {
        if(root==NULL)
        {
            return;
        }
        maxi=max(count,maxi);
        if(leftdir==true)
        {
            solve(root->left,maxi,count+1,false); //go right so increment count and change direction
            solve(root->right,maxi,1,true); //go in same left direction so start from 1 again and dont change direction so let it be true
        }

        else{ //right
            solve(root->right,maxi,count+1,true);
            solve(root->left,maxi,1,false);
        }
    }
    int longestZigZag(TreeNode* root) {
        int maxi=0;
        int count=0;
        solve(root,maxi,count,true);
        solve(root,maxi,count,false);
        return maxi;
    }
};