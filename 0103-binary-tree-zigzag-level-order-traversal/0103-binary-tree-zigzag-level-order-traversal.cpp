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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        q.push(root);
        int alt = 1;
        while(!q.empty()){
            vector<int> v;
            int s = q.size();
            for(int i =0;i<s;i++){
                TreeNode* temp = q.front();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
                v.push_back(temp->val);
                q.pop();
            }
            if(alt == -1){
                reverse(v.begin(),v.end());
            }
            alt = alt*-1;
            ans.push_back(v);
        }
        return ans;
    }
};