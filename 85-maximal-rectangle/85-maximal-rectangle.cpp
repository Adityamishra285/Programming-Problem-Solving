class Solution {
public:
    
    
    void nsl(int n, vector<int>&left, vector<int>&arr){
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
    
    void nsr(int n, vector<int>&right, vector<int>&arr){
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
    
    int mah(int n, vector<int>&arr){
        
        vector<int>left;
        vector<int>right;
        
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        
        nsl(arr.size(), left, arr);
        nsr(arr.size(), right, arr);
        
    
                
        reverse(right.begin(), right.end());
    

        vector<int>width(n, 0);
        
        for(int i=0;i<n;i++){
            width[i] = right[i] - left[i] - 1;
        }
        
        vector<int>res(n, 0);
        
        for(int i=0;i<n;i++){
            res[i] = width[i]*arr[i];
        }
        
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            if(res[i]>maxi){
                maxi = res[i];
            }
        }
        
        
        return maxi;
        
    }
    
    
    
    int maximalRectangle(vector<vector<char>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<int> v;
        for(int j=0;j<m;j++){
            int val = mat[0][j] - '0';
            v.push_back(val);
        }
        
        int maxi = mah(m, v);
        cout<<maxi<<endl;

        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int val = mat[i][j] - '0';
                if(val==0){
                    v[j] = 0;
                }
                else{
                    v[j] = v[j]+val;
                }
            }
            maxi = max(maxi, mah(m, v));

        }
        return maxi;
        
    }
};