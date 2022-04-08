class Solution {
public:
    int scoreOfParentheses(string s) {
        
        stack<int>st;
        int ans = 0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                
                st.push(ans);
                ans = 0;
            }
            
            
            else if(s[i] == ')'){
                int x = st.top();
                int y = max(ans*2, 1);
                ans = x + y;
                st.pop();
            }
            
        }
        return ans;
    }
};