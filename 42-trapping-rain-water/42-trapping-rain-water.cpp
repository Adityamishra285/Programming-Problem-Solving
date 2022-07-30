class Solution {
public:
    int trap(vector<int>& height) {
        
        
        int n = height.size();
        
        vector<int>maxl(n, 0);
        vector<int>maxr(n, 0);
        maxl[0] = height[0];
        maxr[n-1] = height[n-1];
        int lval = height[0];
        int rval = height[n-1];
        
        for(int i=1;i<n;i++){
            if(height[i]>lval){
                maxl[i] = height[i];
                lval = height[i];
            }
            else{
                maxl[i] = lval;
            }
        }
        
//         for(int i=0;i<n;i++){
//             cout<<maxl[i]<<" ";
//         }
//         cout<<endl;
        
        for(int i=n-2;i>=0;i--){
            if(height[i]>rval){
                maxr[i] = height[i];
                rval = height[i];
            }
            else{
                maxr[i] = rval;
            }
        }
        
        // for(int i=0;i<n;i++){
        //     cout<<maxr[i]<<" ";
        // }
        // cout<<endl;
        
        vector<int>minm(n,0);
         int sum = 0;
        
        for(int i=0;i<n;i++){
            minm[i] = min(maxl[i], maxr[i]);
        }
        
        for(int i=0;i<n;i++){
            minm[i] = minm[i]-height[i];
            sum = sum+minm[i];
        }
        
        return sum;
       
        
        
    }
};