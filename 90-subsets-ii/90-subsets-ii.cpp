class Solution {
public:
    
    
    
        void f(int ind, vector<int>arr, vector<vector<int>>&res, vector<int>&temp, set<vector<int>>&s){
        
        if(ind==arr.size()){
           s.insert(temp); 
            // res.push_back(temp);
            return;
        }
        
        f(ind+1, arr, res, temp, s);
        
        temp.push_back(arr[ind]);
        f(ind+1, arr, res, temp, s);
        temp.pop_back();
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>res;
        vector<int>temp;
        sort(nums.begin(), nums.end());
        set<vector<int>>s;
        
        f(0, nums, res, temp, s);
        
        for (auto it : s) {
            res.push_back(it);
    }
        return res;
    }
};