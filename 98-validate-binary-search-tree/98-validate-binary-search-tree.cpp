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
    bool isValidBST(TreeNode* root, long  min_bound=LONG_MIN, long max_bound=LONG_MAX) {
        if(!root) return true;
        if(root->val<=min_bound || root->val>=max_bound) return false;
        return isValidBST(root->left,min_bound,root->val) && isValidBST(root->right,root->val,max_bound);
    }
};