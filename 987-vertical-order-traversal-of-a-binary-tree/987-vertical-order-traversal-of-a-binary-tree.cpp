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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        map<int, map<int,multiset<int>>>mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0,0}});
        while(!q.empty()){
            TreeNode *node=q.front().first;
            int x=q.front().second.first, y=q.front().second.second;
            q.pop();
            mp[x][y].insert(node->val);
            if(node->left) q.push({node->left, {x-1, y+1}});
            if(node->right) q.push({node->right, {x+1,y+1}});
        }
        for(auto i:mp){
            vector<int> v;
            for(auto j:i.second){
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            res.push_back(v);
        }
        return res;
    }
};