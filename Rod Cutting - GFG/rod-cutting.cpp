// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    int f(int ind, int len, int price[], vector<vector<int>> &dp){
        if(ind==0){
            if(ind+1<=len){
                return price[ind]*len;
            }
            else{
                return 0;
            }
        }
        if(len==0){
            return 0;
        }
        
        if(dp[ind][len]!=-1) return dp[ind][len];
        int notpick = 0 + f(ind-1, len, price, dp);
        
        int pick = INT_MIN;
        
        if(ind+1<=len){
            pick = price[ind] + f(ind, len-(ind+1), price, dp);
        }
        
        return dp[ind][len] = max(notpick, pick);
    }
  
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n, vector<int>(n+1, 0));
        
        for(int len=1; len<=n;len++){
            dp[0][len] = len*price[0];
        }
        
        for(int i=0;i<n;i++){
            dp[i][0] = 0;
        }
        
        for(int i=1;i<n;i++){
            for(int len = 1; len<=n;len++){
                int notpick = 0 + dp[i-1][len];
                int pick = INT_MIN;
                int rodlen = i+1;
                if(rodlen<=len)
                    pick = price[i] + dp[i][len-rodlen];
                    dp[i][len] = max(pick, notpick);
            }

        }
        
        return dp[n-1][n];
        
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends