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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return 0;

        if(!subRoot) return 0;

        if(solve(root,subRoot)){
            return 1;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
    bool solve(TreeNode* root, TreeNode* sroot){
        if(!root && !sroot) return 1;

        if(root && sroot && root->val==sroot->val){
            return solve(root->left,sroot->left) && solve(root->right,sroot->right);
        }
        return 0;
        
    }
};
