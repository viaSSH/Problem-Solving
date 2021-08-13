class Solution {

private:
    vector<vector<int>> visited;
public:
    Solution() : visited(300, vector<int> (300, 0)) {}
    int m,n;
    
    void dfs(int x, int y, vector<vector<char>>& grid) {
        if(x < 0 || y < 0 || x >= m || y >= n || visited[y][x] == 1 || grid[y][x] == '0') {
            return;
        }
            
        visited[y][x] = 1;
        
        dfs(x+1, y, grid);
        dfs(x-1, y, grid);
        dfs(x, y+1, grid);
        dfs(x, y-1, grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        
        int ans = 0;
        
        for(int i=0 ; i<n ; i++) {
            for(int j=0 ; j<m ; j++) {
                if(visited[i][j] == 0 && grid[i][j] == '1') {
                    dfs(j, i, grid);    
                    ans++;
                }
                
            }
        }
        
        return ans;
    }
};