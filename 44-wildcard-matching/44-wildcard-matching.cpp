class Solution {
public:
    bool helper(int i, int j, string &s, string &p, vector<vector<int>> &dp){
        //both gets exausted
        if(i<0 and j<0) return true;
        //p gets exausted and s doesn't
        if(j<0 and i>=0) return false;
        //s gets exausted and p doesn't
        if(i<0 and j>=0){
            //if p is not empty, then every single character should be a *
            for(int k=0; k<=j; k++) if(p[k]!='*') return false;
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        //check for a match or a ?
        if((s[i] == p[j]) or (p[j]=='?'))
            return dp[i][j] = helper(i-1, j-1, s, p, dp);
        //check for a sequence by keeping the pointer j static for now and then also chek by removing it for a match 
        else if(p[j]=='*')
            return dp[i][j] = helper(i-1, j, s, p, dp) or helper(i, j-1, s, p, dp);
        return false;
    }
    
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int> (p.size(), -1));
        return helper(s.size()-1, p.size()-1, s, p, dp);
    }
};