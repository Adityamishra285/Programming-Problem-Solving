class Solution {
public:
    
    
    
    
    void f(int ind, int cap, vector<int>&arr, vector<vector<int>>&res, vector<int>temp){
        
//         if(ind>=arr.size()){
//             return;
//         }
        
        if(cap==0){
            res.push_back(temp);
            return;
        }
        
        for(int i = ind;i<arr.size();i++){
            if(i>ind && arr[i]==arr[i-1]){
                continue;
            }
            
            if(arr[i]>cap){
                break;
            }
            
            temp.push_back(arr[i]);
            f(i+1, cap-arr[i], arr, res, temp);
            temp.pop_back();
            
        }
        return;
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        
        vector<vector<int>>res;
        
        sort(candidates.begin(), candidates.end());
        
        vector<int>temp;

        f(0, target, candidates, res, temp);
        
        return res;
        
        
    }
};