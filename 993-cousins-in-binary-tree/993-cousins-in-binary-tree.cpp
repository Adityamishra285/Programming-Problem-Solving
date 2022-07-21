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
    
    
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        if(root==NULL){
            return false;
        }
        
        queue<pair<TreeNode*, TreeNode*>> q;
        
        
        q.push({root, NULL});
        
        while(!q.empty()){
            pair<bool, TreeNode*> xCheck = {false, NULL}, yCheck = {false, NULL};
            int sz = q.size();
            while(sz--){
                auto i = q.front();
                q.pop();
                TreeNode* node = i.first;
                TreeNode* parent = i.second;
                
                if(node->val==x){
                    xCheck = {true, parent};
                }
                else if(node->val==y){
                    yCheck = {true, parent};
                }
                
                if(node->left) q.push({node->left, node});
                if(node->right) q.push({node->right, node});
            }
            if(xCheck.first==true && yCheck.first==true){
            if(xCheck.second!=yCheck.second){
                return true;
            }
            else{
                return false;
            }
        }
        }
        
        return false;
        
    }
};