class Solution {
public:
    // 1 2
    // 4 3
    void go(int x, int y, int num, int dir, vector<vector<int>> & map, int n) {
        if(map[y][x] != 0) {
            return;
        }
        
        map[y][x] = num;
        if(n == 1) {
            return;
        }
        if(dir == 0) {
            if(x+1 < n && map[y][x+1] == 0) {
                go(x+1, y, num+1, dir, map, n);
            }
            else{
                go(x, y+1, num+1, dir+1, map, n);
            }
        }
        else if(dir == 1) {
            if(y+1 < n && map[y+1][x] == 0) {
                go(x, y+1, num+1, dir, map, n);
            }
            else{
                go(x-1, y, num+1, dir+1, map, n);
            }
        }
        else if(dir == 2) {
            if(x-1 >= 0 && map[y][x-1] == 0) {
                go(x-1, y, num+1, dir, map, n);
            }
            else{
                go(x, y-1, num+1, dir+1, map, n);
            }
        }
        else if(dir == 3) {
            if(y-1 >= 0 && map[y-1][x] == 0) {
                go(x, y-1, num+1, dir, map, n);
            }
            else{
                go(x+1, y, num+1, 0, map, n);
            }
        }
        
        
        
    }
    
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> map(n, vector<int>(n,0));
        
        // r-0, d-1, l-2, u-3
        go(0, 0, 1, 0, map, n);
        
        return map;
    }
};