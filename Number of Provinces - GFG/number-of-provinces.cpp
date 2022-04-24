// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    // void bfs(int start, vector<vector<int>> &adj, vector<int>&vis){
    //     queue<int>q;
    //     q.push(start);
    //     vis[start] = 1;
        
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
            
    //         for(int i = 0;i<adj[node].size();i++){
    //             if(vis[i]==0 && adj[node][i]==1){
    //                 vis[i] = 1;
    //                 q.push(i);
    //             }
    //         }
    //     }
    // }
    
    void dfs(int s, vector<vector<int>> &adj, vector<int>&vis){
        vis[s] = 1;
        
        for(int i = 0;i<adj[s].size();i++){
            if(vis[i]==0 && adj[s][i]==1){
                dfs(i, adj, vis);
            }
        }
        
    }
            
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> vis(V, 0);
        int count = 0;
  
        for(int i=0;i<V;i++){
            if(vis[i]==0){
                count++;
                dfs(i, adj, vis);
            }
            
        }
        
        return count;
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends