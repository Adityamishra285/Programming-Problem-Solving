class Solution {
public:
    
    
    bool isPlaindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    
    
    void f(int ind, string s, vector<string>temp, vector<vector<string>>&res){
        
        if(ind==s.length()){
            res.push_back(temp);
            return;
        }
        
        for(int i=ind;i<s.length();i++){
            if(isPlaindrome(s, ind, i)){
                temp.push_back(s.substr(ind, i-ind+1));
                f(i+1, s, temp, res);
                temp.pop_back();
            }
        }
        return;
        
        
    }
    
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>>res;
        vector<string>temp;
        
        f(0, s, temp, res);
        
        return res;
        
    }
};