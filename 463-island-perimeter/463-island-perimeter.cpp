class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int map[102][102] = {0,};
        int H = grid.size();
        int W = grid[0].size();
        int answer = 0;
        
        for(int i=0 ; i<H ; i++) {
            for(int j=0 ; j<W ; j++) {
                map[i+1][j+1] = grid[i][j];
            }
        }
        
        for(int i=1 ; i<=H ; i++) {
            for(int j=1 ; j<=W ; j++) {
                int island = 0;
                if(map[i][j] == 0) {
                    continue;
                }
                if(map[i-1][j] == 1) {
                    island++;
                }
                if(map[i+1][j] == 1) {
                    island++;
                }
                if(map[i][j+1] == 1) {
                    island++;
                }
                if(map[i][j-1] == 1) {
                    island++;
                }
                answer += (4 - island);
            }
        }
        
        return answer;
    }
};

// 0 - > 4
// 1 -> 3
// 2 -> 2
// 3 -> 1
// 4 -> 0

