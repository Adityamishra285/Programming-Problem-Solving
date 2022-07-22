class Solution {
public:
    
    
    void f(int ind, vector<int>&arr, int cap, vector<int>temp, vector<vector<int>>&res){
        
        
        
        if(ind==-1){
            return;
        }
        if(cap==0){
            res.push_back(temp);
            return;
        }
        
        f(ind-1, arr, cap, temp,res);
        
        if(arr[ind]<=cap){
            temp.push_back(arr[ind]);
           f(ind, arr, cap-arr[ind], temp, res);
            temp.pop_back();
            
        }
             
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>res;
        vector<int>temp;
        f(n-1, candidates, target, temp, res);
        
        return res;
        
    }
};