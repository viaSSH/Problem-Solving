class Solution {
public:
    int W, H;
    void dfs(int w, int h, vector<vector<bool>> &visited, vector<vector<int>> &heights) {
        
        if(visited[h][w]) {
            return;
        }
        
        visited[h][w] = true;
        
        // left
        if(w-1>=0 && heights[h][w-1] >= heights[h][w]) {
            dfs(w-1, h, visited, heights);
        }
        // right
        if(w+1<W && heights[h][w+1] >= heights[h][w]) {
            dfs(w+1, h, visited, heights);
        }
        //down
        if(h+1<H && heights[h+1][w] >= heights[h][w]) {
            dfs(w, h+1, visited, heights);
        }
        //up
        if(h-1>=0 && heights[h-1][w] >= heights[h][w]) {
            dfs(w, h-1, visited, heights);
        }
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        W = heights[0].size();
        H = heights.size();
        
        vector<vector<bool>> pacific(201, vector<bool>(201, false));
        vector<vector<bool>> atlantic(201, vector<bool>(201, false));
        
        
        
        for(int i=0 ; i<W ; i++) {
            // paci top
            dfs(i, 0, pacific, heights);
            
            // atlan down
            dfs(i, H-1, atlantic, heights);
        }
        
        for(int i=0 ; i<H ; i++) {
            // paci left
            dfs(0, i, pacific, heights);
            
            // atlan right
            dfs(W-1, i, atlantic, heights);
        }
        
        for(int i=0 ; i<H ; i++) {
            for(int j=0 ; j<W ; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};

