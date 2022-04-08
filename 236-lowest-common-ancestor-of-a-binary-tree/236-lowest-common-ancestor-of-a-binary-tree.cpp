/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    TreeNode*preorder(TreeNode*root, int n, int m){
        if(root==NULL)
            return NULL;
        
        if(root->val==n || root->val==m)
            return root;
        
        TreeNode *left = preorder(root->left, n, m);
        TreeNode *right = preorder(root->right, n, m);
        
        if(left && right)
            return root;
        
        if(left)
            return left;
        if(right)
            return right;
        
        else 
            return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            
            return preorder(root, p->val, q->val);
        
    }
};