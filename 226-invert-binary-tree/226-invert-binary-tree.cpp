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
    TreeNode *solve(TreeNode*root){
        if(root==NULL){
            return NULL;
        }
        
        TreeNode *left = solve(root->left);
        TreeNode  *right = solve(root->right);
        
            
        root->left = right;
        root->right = left;

        return root;
        
        
    }
    TreeNode* invertTree(TreeNode* root) {
        return solve(root);
        
    }
};