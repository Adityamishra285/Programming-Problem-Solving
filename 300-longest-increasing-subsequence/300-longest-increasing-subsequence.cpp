class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int prev = ind-1; prev>=-1;prev--){
                int notpick = 0 + dp[ind+1][prev+1];
                int pick = 0;
                if(prev==-1 || nums[ind]>nums[prev]){
                    pick = 1 + dp[ind+1][ind+1];
                }
                dp[ind][prev+1] = max(pick, notpick);
            }
        }
        
        return dp[0][0];
    }
};