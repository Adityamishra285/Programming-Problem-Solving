// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution{
    public:
    
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        
        Node(int x){
            data = x;
            left = NULL;
            right = NULL;
        }
    };
    
    int idx=0;
    unordered_map<int, int>mp;
    bool isPossible = true;
    
     Node* tree(int pre[], int in[], int lb, int ub){
         
         if(lb>ub)
            return NULL;

         Node* root = new Node(pre[idx]);
         auto m = mp.find(pre[idx]);
         if(m==mp.end()){
             isPossible = false;
             return NULL;
         }
         int mid = mp[pre[idx]];
         idx++;
         root->left = tree(pre, in, lb, mid-1);
         root->right = tree(pre, in, mid+1, ub);
         
         return root;
         
     }
    
    void postodr(Node* root, vector<int>& post){
        if(root==NULL)
            return;
        postodr(root->left, post);
        postodr(root->right, post);
        
        post.push_back(root->data);
        
        
    }
    
    bool checktree(int preorder[], int inorder[], int postorder[], int n) 
    { 
    	// Your code goes here
    	for(int i=0;i<n;i++){
    	    mp[inorder[i]] = i;
    	}
    	Node* root = tree(preorder, inorder, 0, n-1);
    	vector<int>post;
    	postodr(root, post);
    	
    	if(!isPossible){
    	    return false;
    	}
    	
    	bool flag = true;
    	
    	for(int i=0;i<n;i++){
    	    if(postorder[i]!=post[i]){
    	        flag = false;
    	    }
    	}
    	
    	return flag;
    	
    	

        
    } 

};


// { Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int preorder[n];
		int inorder[n];
		int postorder[n];

		for (int i = 0; i < n; ++i)
			cin>>preorder[i];

		for (int i = 0; i < n; ++i)
			cin>>inorder[i];

		for (int i = 0; i < n; ++i)
			cin>>postorder[i];
        
        Solution obj;
		if(obj.checktree(preorder, inorder, postorder, n))
			cout << "Yes\n";
		else
			cout<<"No\n";
	} 
	return 0; 
} 

  // } Driver Code Ends