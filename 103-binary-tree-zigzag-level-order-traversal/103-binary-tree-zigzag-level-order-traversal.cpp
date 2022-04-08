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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        if(root==NULL)
            return res;
        
        bool RighttoLeft = false;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> v(size);
            int index = 0;
            for(int i=0;i<size;i++){
                if(RighttoLeft){
                    index = size-1-i;
                }
                else{
                    index = i;
                }
                TreeNode *temp = q.front();
                q.pop();
                v[index] = temp->val;
                if(temp->left)
                    q.push(temp->left);
                
                if(temp->right)
                    q.push(temp->right);
            }
            RighttoLeft = !RighttoLeft;
                
                res.push_back(v);
        }
        return res;
        
    }
};