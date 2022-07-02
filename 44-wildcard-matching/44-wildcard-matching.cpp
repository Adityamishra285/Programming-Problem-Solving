class Solution {
public:
    bool helper(int i, int j, string &p, string &s, vector<vector<int>> &dp){
        //both gets exausted
        if(i<0 and j<0) return true;
        //p gets exausted and s doesn't
        if(i<0 and j>=0) return false;
        //s gets exausted and p doesn't
        if(j<0 and i>=0){
            //if p is not empty, then every single character should be a *
            for(int k=0; k<=i; k++) if(p[k]!='*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //check for a match or a ?
        if((s[j] == p[i]) or (p[i]=='?'))
            return dp[i][j] = helper(i-1, j-1, p, s, dp);
        //check for a sequence by keeping the pointer j static for now and then also chek by removing it for a match 
        else if(p[i]=='*')
            return dp[i][j] = helper(i-1, j, p, s, dp) or helper(i, j-1, p, s, dp);
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(p.size(), vector<int> (s.size(), -1));
        return helper(p.size()-1, s.size()-1, p, s, dp);
    }
};