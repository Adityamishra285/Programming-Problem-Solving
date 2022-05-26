// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    /*
    Remember that in question that you have done in DP notebook (maze with obstecles) their are
    only 2 paths (Down and Right) so agar tum soch rhe ho ki usme Visited array kyu nhi use hua
    to uska reason ye hai ki agar tm Ek baar Down gye to tum us down element se Up (parent)
    kabhi jaa hi nhi skte. 
    mtlb sirf down and right jaa skte to opposite jaa hi nhi skte to us path ko
    wapas traverse kr hi nhi skte, but is question me all 4 direction jaa skte, isiliye ek visited
    array hai jo track rkh rha (LIKE DFS) kyuki idhr agar tm Down gye to, us down wale element se
    UP wapas usi parent wale pe jaa kste ho (jisse infinite loop hogi (DFS without VISITED array))
    kyuki UP allowed hai (opposite direction).
    
    Concept:
    Simple hai, tm boundry conditions check kr rhe, ki jo i&j hai (rows and col) wo n-1 se chota
    hona chhiye and 0 ya 0 se bada. phir tm main me sidha check kr rhe ki agar staring index 
    and (n-1)(n-1) 1 hai ki nhi, kyuki agar 1 nhi hoga to tm kbhi destination reach hi 
    nhi kr skte (think)
    Tb last me tm func call kr rhe, jo ek baar Down, left, right, Up jaa rha, cause DLRU 
    lexo sorted hai. phir tm har direction me dfs call kr rhe. Phir usko visit kr rhe or agar 
    us path se kahi or nhi jaa skte tb tm backtrack kr rhe after reaching (n-1,n-1). 
    Backtrack krte waqt tm vis wale cell ko wapas se unVis kr rhe kyuki ho skta ki us cell 
    se kisi or direction me jaane se koi or path possible ho jaise example ka 3,0 cell se backtrack
    kra to 2,0 pe gye or 3,0 ko unVIs kr diya, to ab jab 2,0 se Down gye to to ab right jaane ka 
    turn hai (left not possible) to ab new path banega and niche wale saare unVis ho gye honge
    backtrack krte waqt.
    path possible ho to us cell ko
    */
    
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