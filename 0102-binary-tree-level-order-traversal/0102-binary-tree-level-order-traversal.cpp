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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty())
        {
            vector<int>help;
            int s=q.size();
            while(s>0)
            {
                TreeNode* it=q.front();
                q.pop();
                s--;
                help.push_back(it->val);
                if(it->left!=NULL) q.push(it->left);
                if(it->right!=NULL) q.push(it->right);
            }
            ans.push_back(help);
        }
        return ans;
    }
};