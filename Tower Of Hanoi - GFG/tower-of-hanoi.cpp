// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    //Function to count number of subtrees having sum equal to given sum.
// (n, A, B, C) where B is auxilary intial
// (n-1, A, C, B) A to B using C -> Recursive
// A to C print
// (n-1, B, A, c) B to C using A -> Recursive
    
    void solve(int n, int A, int Aux, int C, long long &count){
            if(n==1){
             cout<< "move disk " << n << " from rod " << A << " to rod " << C << endl;
             count++;
             return;
        }
            count++;
            solve(n-1, A, C, Aux, count);
            cout<< "move disk " << n << " from rod " << A << " to rod " << C<<endl; 
            solve(n-1, Aux, A, C, count);
    }
    
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long count = 0;
         
        solve(N, from, aux, to, count);
        return count;
}

};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends