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
    
    void solve(TreeNode* node, vector<string> &res, string str){
        
        if(node==NULL){
            return;  
        }
        if(node->left==NULL && node->right==NULL){
            str = str + to_string(node->val);
            res.push_back(str);
            return;
        }
        str = str + to_string(node->val) + "->";
        solve(node->left, res, str);
        solve(node->right, res, str);

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str = "";
        solve(root, res, str);
        return res;
    }
};