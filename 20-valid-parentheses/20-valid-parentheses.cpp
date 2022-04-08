class Solution {
public:
    bool isValid(string s) {
        
        stack<char>st;
        
        int n = s.length();
        int count=0;
        

        
        for(int i=0;i<n;i++){

            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
                continue;
            }
            
            if(st.empty())
                return false;
            
            if(s[i]==')'){
                if(st.top()=='('){
                st.pop();
                continue;
                }
                else
                    return false;
            }
            
            else if(s[i]==']'){
                if(st.top()=='['){
                st.pop();
                continue;
                }
                else
                    return false;
            }

            else if(s[i]=='}'){
                if(st.top()=='{'){
                st.pop();
                continue;
                }
                else
                    return false;
            }
        }
        
        return (st.empty());
    }
};