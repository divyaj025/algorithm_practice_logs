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
    int help(TreeNode* root, int &maxi)
    {
        if(!root) return 0;
        int lsum=INT_MIN;
        lsum=max(0,help(root->left,maxi));
        int rsum=INT_MIN;
        rsum=max(0,help(root->right,maxi));
        maxi=max(maxi,lsum+rsum+root->val);
        return root->val+max(lsum,rsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        help(root,maxi);
        return maxi;
    }
};