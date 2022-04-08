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
    unordered_map<int,int>mp;
    int idx ;
    
    TreeNode* solve(vector<int>inorder, vector<int>postorder, int lb, int ub){
        if(lb>ub)
            return NULL;
        
        TreeNode *res = new TreeNode(postorder[idx]);
        idx--;
        
        int mid = mp[res->val];
        
        res->right = solve(inorder, postorder, mid+1, ub);
        res->left = solve(inorder, postorder, lb, mid-1);
        
        
        return res;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = postorder.size();
        idx = n-1;
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, n-1);
    }
};