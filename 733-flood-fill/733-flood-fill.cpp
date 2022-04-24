class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int sr, int sc, int src, int newColor){
        
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size() || image[sr][sc]!=src)
            return;
        
        image[sr][sc] = newColor;
        
        dfs(image, sr-1, sc, src, newColor);
        dfs(image, sr+1, sc, src, newColor);
        dfs(image, sr, sc-1, src, newColor);
        dfs(image, sr, sc+1, src, newColor);
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        /*By checking newColor with source color(image[sr][sc]==newColor), we dont have to use visited array, why? imagine ki both src and newcolor 
            is same (for example src==newcolor==1) now we dont keep visited array then because using DFS it go into infinite loop (if src is 1 and new color is 1 1<->1<->1 to hmlog 1 ko 1 se hi change krdiye imagine, 1<->1<->1, now if we go left (call DFS) or right from center and we dont have visited array then left dfs will be call on center also (as all directions, up, down, left, right) and then again from center to left and again from left to center, so infinite loop, so to avoid this we can use visited array (so that once visited a cell then dont visit it again) just like in DFS or we can use a CONDITION which is if the source and newcolor is same then we will return the original image itself (because we have to call dfs or change color of pixels(cells) which is equal to source) so if we starting me hi value same hai dono ki to return krdo original ko hi, agar same nhi hai to hum color zaroor change krenge src ka newColor me, to ye change krna hi visited jaisa kaam kr rha. for example newcolor = 3, then 1<->1<->1 tb ab jab src se start kiya to src ab 1 se 3 ho jayega (1<->3<->1) to jb left me jayenge or uska dfs call hoga to jb wo center me ayega to usko 3 mile and humlog ko sirf src wale cells pe call krna hai jiska value src ke equal hai (in this case 1, call if cell value is 1(src)) to ab ye center pe call nhi hua to ek tarah se visited jaise ho gya. 
            to NO EXTRA SPACE
        */
        if(image[sr][sc]==newColor)
            return image;
        
        dfs(image, sr, sc, image[sr][sc], newColor);
        
        return image;
        
        
    }
};