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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        int lvl=0;
        level(root,0);

        return ans;
    }
    void level(TreeNode* node,int depth){
        if(!node) return;

        if(ans.size()==depth){
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(node->val);
        level(node->left,depth+1);
        level(node->right,depth+1);
    }
};
