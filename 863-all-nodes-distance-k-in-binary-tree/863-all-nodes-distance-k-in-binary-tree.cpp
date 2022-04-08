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
    
    unordered_map<TreeNode*, int>mp;
    
    void Target(TreeNode*root, TreeNode* &head, TreeNode* &target, int &value){
        if(root==NULL)
            return;
        if(root->val==target->val)
        {
            head = root;
            mp[head]++;
            value = head->val;
        }
        Target(root->left, head, target, value);
        Target(root->right, head, target, value);
        
        return;
        
    }
    void solve(TreeNode* &head, vector<int> &res, int count, int &k){
        if(head==NULL){
            return;
        }
        if(count==k){
            res.push_back(head->val);
            mp[head]++;
        }

        solve(head->left, res, count+1, k);
        solve(head->right, res, count+1, k);
        return;
    }
    
   void par(TreeNode* root, TreeNode* &head, TreeNode* &parent){
       if(root==NULL)
           return;
       if(root->left==head){
           parent = root;
           return;
       }
       else if(root->right==head){
           parent = root;
           return;
       }
       else{
            par(root->left, head, parent);
            par(root->right, head, parent);
       }    
       return;
       
   }
    
    bool allPar(TreeNode* root, vector<TreeNode*>&arr, TreeNode* &parent){
        
        if(!root)
            return false;
        
        arr.push_back(root);
        
        if(root==parent)
            return true;
        if(allPar(root->left, arr, parent) || allPar(root->right, arr, parent))
            return true;
        
        arr.pop_back();
        return false;
    }
    
    void help(TreeNode* root, int d, vector<int> &res, int &k, int &value, int count, int &distance){
        
        if(root==NULL)
            return;
            
        if(k-distance>0){
            if(count<=d){
                if(count==d){
                    if(root->val!=value){
                        auto i = mp.find(root);
                        if(i==mp.end()){
                            res.push_back(root->val);
                            return;
                        }
                        else
                            return;
                }
            }
                else{
                    mp[root]++;
                    auto i = mp.find(root->left);
                    if(i==mp.end()){
                        help(root->left, d, res, k, value, count+1, distance);
                        }
                    auto x = mp.find(root->right);
                    if(x==mp.end()){
                        help(root->right, d, res, k, value, count+1, distance);
                        return;
                    }
                }   
            }
            else{
                return;
            }
        }
        else{
            if(distance<=k && root->val!=value){
                auto i = mp.find(root);
                        if(i==mp.end()){
                            res.push_back(root->val);
                            return;
                        }
            }
                
        }
    }
    
    void solve2(TreeNode* root, TreeNode* &parent, vector<int> &res, int &k, int &value){
        
        
        vector<TreeNode*> arr;
        bool a = allPar(root, arr, parent);
        reverse(arr.begin(), arr.end());
        
        // for(auto x:arr){
        //     mp[x]++;
        // }
        // cout<<"Arr vector values are: "<<endl;
        // for(auto x:arr){
        //     cout<<x->val<<" ";
        // }
        // cout<<endl;
        int d = k-1;
        int distance = 1;
        for(auto x:arr){
            TreeNode* temp = x;
            help(temp, d, res, k, value, 0, distance);
            d--;
            distance++;
        }
        // cout<<"Res vector values are: "<<endl;
        // for(int i=0;i<res.size();i++){
        //     cout<<res[i]<<" ";
        // }
    }
    

    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        TreeNode* head;
        TreeNode* parent;
        vector<int> res;
        int value = 0;
        int count = 0;
        int d = 0;
        if(root==NULL || root->left==NULL && root->right==NULL)
            return res;
        
        Target(root, head, target, value);
        solve(head, res, count, k);
        par(root, head, parent);
        solve2(root, parent, res, k, value);
        
        
        return res;
        
    }
};