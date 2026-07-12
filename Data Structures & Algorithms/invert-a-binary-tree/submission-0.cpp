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
    TreeNode* invertTree(TreeNode* root) {
        return helper(root);
    }
    TreeNode* helper(TreeNode* root){
        if(!root) return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        right = helper(right);
        left = helper(left);
        root->left = right;
        root->right = left;
        return root;
    }
};
