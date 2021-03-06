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
   TreeNode* insucc(TreeNode* root){
       TreeNode* temp=root;
       while(temp->left !=NULL){
            temp=temp->left;
        }
        return temp;
   }
     
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root==NULL) 
        {
             return NULL;
        }  
        
        if(root->val == key){
            // CASE 1: if node has 0 child
            if(root->left == NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            
            // CASE 2: if node has 1 child
            // if right child
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            // if left child
            else if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            
            // CASE 3:  if node has 2 children
            if(root->left!=NULL && root->right!=NULL){
                /* 2 options: 
                1. take minimum value from right subtree
                2. take maximum value from left subtree*/
                
                // using option 1
                int minval=insucc(root->right) ->val;  // function call
                root->val=minval;   // copy minimum value at root node
                root->right = deleteNode(root->right, minval);
               
            }
        }
        else if(root->val > key){
            root->left= deleteNode(root->left, key);
          }
        else{
            // root->val < key
            root->right = deleteNode(root->right, key);
        }
       return root;
    }
};