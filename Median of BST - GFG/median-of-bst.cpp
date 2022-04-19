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



float findMedian(struct Node* node);

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
   //cout << t << endl;
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root = buildTree(s);

      // getline(cin, s);
       
        cout << findMedian(root) << endl;

      // cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

void count(Node* root, int &c){
    if(root==NULL)
        return;
    
    c++;
    count(root->left, c);
    count(root->right, c);
    
    return;
    
}

float findMedian(struct Node *root)
{
      //Code here
      
      int c = 0;
      count(root, c);
      float even = c/2;
      float odd = (c+1)/2;
      Node* cur = root;
      if(c%2==0){
          int i = 1; int j = 1; float x = 0; float y = 0;
          while(cur){
          if(cur->left==NULL)
          {
            //   res.push_back(cur->data);
            if(i==even)
                x = cur->data;
            if(j==even+1)
                y = cur->data;
            i++;
            j++;
              cur = cur->right;
          }
          else{
              Node* prev = cur->left;
              while(prev->right && prev->right!=cur){
                  prev = prev->right;
              }
              
              if(prev->right == NULL){
                  prev->right = cur;
                  cur = cur->left;
              }
              else if(prev->right==cur){
                  prev->right = NULL;
                //   res.push_back(cur->data);
                if(i==even)
                    x = cur->data;
                if(j==even+1)
                    y = cur->data;
                i++;
                j++;
                  cur = cur->right;
              }
              
          }
      }
      float val =  (x+y)/2;
      return val;
    }
      else{
          float i = 1;
          float res = 0;
          while(cur){
          if(cur->left==NULL)
          {
            //   res.push_back(cur->data);
            // cout<<cur->data<<endl;
            if(i==odd){
                return cur->data;
                return res;
            }
                
            
            i++;
              cur = cur->right;
          }
          else{
              Node* prev = cur->left;
              while(prev->right && prev->right!=cur){
                  prev = prev->right;
              }
              
              if(prev->right == NULL){
                  prev->right = cur;
                  cur = cur->left;
              }
              else if(prev->right==cur){
                prev->right = NULL;
                //   res.push_back(cur->data);
                // cout<<cur->data<<endl;
                if(i==odd){
                res = cur->data;
                return res;
            }
                i++;
                cur = cur->right;
              }
              
          }
      }
    //   for(int i=0;i<res)
    }
    // 1 3 6 10 11 12 13 15 18 20
}

