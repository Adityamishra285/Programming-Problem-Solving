class Solution {
public:
    
    void nsl(vector<int>&arr, vector<int>&left){
        int n = arr.size();
        stack<int>st;
    
        for(int i=0;i<n;i++){
            if(st.empty()){
                left.push_back(-1);
            }
            else if(!st.empty() && arr[st.top()]<arr[i]){
                left.push_back(st.top());
            }
            else if(!st.empty() && arr[st.top()]>=arr[i]){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    left.push_back(-1);
                }
                else{
                    left.push_back(st.top());
                }
            }
            
            st.push(i);
            
        }
    }
    
    void nsr(vector<int>&arr, vector<int>&right){
        int n = arr.size();
        stack<int>st;
    
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right.push_back(n);
            }
            else if(!st.empty() && arr[st.top()]<arr[i]){
                right.push_back(st.top());
            }
            else if(!st.empty() && arr[st.top()]>=arr[i]){
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(st.empty()){
                    right.push_back(n);
                }
                else{
                    right.push_back(st.top());
                }
            }
            
            st.push(i);
            
        }
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int>left;
        vector<int>right;
        int n = heights.size();
        
        nsl(heights, left);
        nsr(heights, right);
        reverse(right.begin(), right.end());
        
        vector<int>width(n, 0);
        
        for(int i=0;i<left.size();i++){
            width[i] = right[i]-left[i] - 1;
        }
        
        vector<int>res(n, 0);
        for(int i=0;i<left.size();i++){
            res[i] = width[i]*heights[i];
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            if(res[i]>maxi){
                maxi = res[i];
            }
        }
        
        return maxi;
        
        
    }
};