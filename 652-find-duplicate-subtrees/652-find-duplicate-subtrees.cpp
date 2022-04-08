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
    
    string solve(TreeNode *root, unordered_map<string, int> &mp1, unordered_map<string, TreeNode*> &mp2){
        
        string s = "";
        if(root == NULL)
        {
            s = '*';
            return s;
        }
        
        s = s + '*' + to_string(root->val);
        s = s + solve(root->left, mp1, mp2);
        s = s + solve(root->right, mp1, mp2);
        
        mp1[s]++;
        mp2[s] = root;
        return s;
        
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> mp1;
        unordered_map<string, TreeNode*>mp2;
        vector<TreeNode*> res;
        solve(root, mp1, mp2);
        
        for(auto x:mp1){
            if(x.second>=2){
                auto i = mp2.find(x.first);
                if(i!=mp2.end()){
                    res.push_back(i->second);    
                }
                
            }
        }
        return res;
        
        
    }
};