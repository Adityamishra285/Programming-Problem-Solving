// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    
    int floor(Node* root, int &k){
        
        int f = -1;
        
        while(root){
            
            if(root->data==k){
                f = root->data;
                return f;
            }
            
            if(root->data<k){
                f = root->data;
                root = root->right;
            }
            else if(root->data>k){
                root = root->left;
            }
            
        }
        return f;
    }
    
    int ceil(Node* root, int k){
        int c = -1;
        
        while(root){
            
            if(root->data==k){
                c = root->data;
                return c;
            }
            
            if(root->data<k){
                root = root->right;
            }
            else if(root->data>k){
                 c = root->data;
                root = root->left;
            }
            
        }
        return c;
    }
    
    int minDiff(Node *root, int K)
    {
        //Your code here
        int f = floor(root, K);
        int c = ceil(root, K);
        
        int fd = abs(f-K);
        int cd = abs(c-K);
        
        
        return min(fd,cd);
    }
};


// { Driver Code Starts.

// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       int k = stoi(s);
       // getline(cin, s);

        Solution ob;
       cout << ob.minDiff(root1, k);
        cout << endl;
       //cout<<"~"<<endl;
   }
   return 0;
}
  // } Driver Code Ends