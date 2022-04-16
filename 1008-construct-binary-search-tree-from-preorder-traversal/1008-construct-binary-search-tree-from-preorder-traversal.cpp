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
    
    int idx = 0;
    unordered_map<int, int>mp;
        //8 5 1 7 10 12
        //1 5 7 8 10 12
    
    TreeNode* create(vector<int>pre, vector<int>in, int lb, int ub){
        
        if(lb>ub){
            return NULL;
        }
        TreeNode* root = new TreeNode(pre[idx]);
        int mid = mp[pre[idx]];
        idx++;
        
        root->left = create(pre, in, lb, mid-1);
        root->right = create(pre, in, mid+1, ub);
        
        return root;
        
    }
    
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        vector<int> inorder;
    
        int n = preorder.size();
        
        for(int i=0;i<n;i++){
            inorder.push_back(preorder[i]);
        }
        
        sort(inorder.begin(), inorder.end());
        
        for(int i=0;i<n;i++){
            mp[inorder[i]] = i;
        }
        
        TreeNode* root = create(preorder, inorder, 0, n-1);
        
        return root;

    }
};