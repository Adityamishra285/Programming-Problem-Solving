// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{



    public:
    int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
    
    queue<pair<int ,pair<int, int>>> q;   // pair< no_of_steps & pair <i, j>>
    
    q.push({0, {KnightPos[0], KnightPos[1]}});    // initial coordinates
    
    vector<vector<int>> v{{1, 2}, {-1,-2}, {-1, 2}, {1, -2},
                          {2, 1}, {-2,-1}, {-2, 1}, {2, -1}
    };  // all 8 directions
    
    vector<vector<bool>> visited(N+1, vector<bool> (N+1, false));  // visited vector
    
    visited[KnightPos[0]][KnightPos[1]]=true;  // initailly true for knight initial position
    
    while(!q.empty()){
        
           int c = q.front().first; // counter of steps
           
           pair<int, int> cord = q.front().second;
           
           int i = cord.first;   // coordinates
           int j = cord.second;   // coordinates
           
           q.pop();
           
           if(i==TargetPos[0] && TargetPos[1]==j){
               return c;
           }
           
           for(auto it : v){
               int new_i = it[0] + i;
               int new_j = it[1] + j;
               
               if( new_i <= N && new_j <= N && new_i > 0 && new_j > 0 && visited[new_i][new_j] == false ){
                   q.push({c+1, {new_i, new_j}});   // push (counter+1) along with new coordiantes;
                   visited[new_i][new_j] = true;
               }
           }
    }
    return -1;
}
    //Function to find out minimum steps Knight needs to reach target position.
// 	int minStepToReachTarget(vector<int>&K,vector<int>&T,int N)
// 	{
// 	    // Code here
// 	    int sum = 0;
// 	    vector<vector<int>> vis(N+1, vector<int>(N+1, 0));
// 	    vector<vector<int>> dir{{1,2},{-1,-2},{-1,2},{1,-2},{2,1},{-2-1},{-2,1},{2,-1}};
	    
// 	    queue<pair<int,pair<int,int>>> q;
	    
// 	    q.push({0, {K[0], K[1]}});
// 	    vis[K[0]][K[1]]=1;
	   
// 	    while(!q.empty()){
	            
// 	       sum = q.front().first;
// 	       pair<int, int> ij = q.front().second;
//             int i = ij.first;
//             int j = ij.second;
//             q.pop();
            
//             if(i==T[0] && j==T[1]){
//                 return sum;
//             }
            
//             for(auto it:dir){
//                 int new_i = it[0] + i;
//                 int new_j = it[1] + j;
                
//                 if(new_i <=N && new_j <=N && new_i>0 && new_j>0 && vis[new_i][new_j] == 0){
//                     q.push({sum+1, {new_i, new_j}});
//                     vis[new_i][new_j] = 1;
//                 }
//             }
//     }
//     return -1;
// 	}
	
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends