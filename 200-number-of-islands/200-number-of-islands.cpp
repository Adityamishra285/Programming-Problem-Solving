class Solution {
public:
    void depthfirst(int row, int col, vector<vector<char>>&grid, int n, int m, vector<vector<int>>&vis){
        if(row>=n || col>=m || row<0 || col<0 || grid[row][col]=='0' || vis[row][col]==1){
            return;
        }

        else{
            vis[row][col]=1;
            depthfirst(row-1, col, grid, n, m, vis);
            depthfirst(row+1, col, grid, n, m, vis);
            depthfirst(row, col-1, grid, n, m, vis);
            depthfirst(row, col+1, grid, n, m, vis);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    count+=1;
                    depthfirst(i, j, grid, n, m, vis);
                    
                }
            }
        }
        return count;
    }
};