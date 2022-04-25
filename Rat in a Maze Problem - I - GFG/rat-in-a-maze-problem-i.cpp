// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void fun(int i, int j, vector<vector<int>> &m, int n, vector<string> &res, string str, vector<vector<int>>&vis){
        if(i==n-1 && j==n-1){
            res.push_back(str);
            return;
        }
        
        if(i<0 || j<0 || i>n-1 || j>n-1){
            return;
        }
        
        if(vis[i][j]==1 || m[i][j]==0){
            return;
        }
        // down left right up (sorted order traversal(lexographical))
        vis[i][j]=1;
        fun(i+1, j, m, n, res, str+'D', vis);
        fun(i, j-1, m, n, res, str+'L', vis);
        fun(i, j+1, m, n, res, str+'R', vis);
        fun(i-1, j, m, n, res, str+'U', vis);
        // backtracking step unvisit the position
        vis[i][j]=0;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        int src = m[0][0];
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> res;
        if(m[0][0]==0 || m[n-1][n-1]==0)
            return res;

        fun(0, 0, m, n, res, "", vis);
        
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends