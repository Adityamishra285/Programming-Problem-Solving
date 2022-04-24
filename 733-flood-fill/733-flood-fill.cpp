class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int src, int newColor, vector<vector<int>>&vis){
        
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=src || vis[sr][sc]==1)
            return;
        
        vis[sr][sc] = 1;
        image[sr][sc] = newColor;
        
        dfs(image, sr-1, sc, src, newColor, vis);
        dfs(image, sr+1, sc, src, newColor, vis);
        dfs(image, sr, sc-1, src, newColor, vis);
        dfs(image, sr, sc+1, src, newColor, vis);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        // if(image[sr][sc]==newColor)
        //     return image;
        
        vector<vector<int>> vis(image.size(), vector<int>(image[0].size(),0));
        
        dfs(image, sr, sc, image[sr][sc], newColor, vis);
        
        return image;
        
        
    }
};