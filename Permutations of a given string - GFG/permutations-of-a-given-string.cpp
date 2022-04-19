// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
public:
void permute(string s, int l, int r, vector<string> &res){
        if(l==r)
            res.push_back(s);
        
        else{
           for(int i=l; i<=r;i++){
               swap(s[l], s[i]);
               permute(s, l+1, r, res);
               swap(s[l], s[i]);
           }
        }
        
        
    }
vector<string>find_permutation(string S)
{                     		    // Code here there
    vector<string>res;
    int n = S.size();
    permute(S, 0, n-1,res);
    sort(res.begin(), res.end());
    return res;
    }                    	
                        		
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends