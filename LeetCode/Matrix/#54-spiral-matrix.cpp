class Solution {

private:
    int width, height;
    
public:
    bool isOver(vector<vector<int>>& mat, int h, int w) {
        if(h < 0 || h >= height || w < 0 || w >= width) return true;
        if(mat[h][w] == -1000) return true;
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        
        width = matrix[0].size();
        height = matrix.size();
        bool right = true;
        bool down = false;
        bool left = false;
        bool up = false;
        
        int x = -1;
        int y = 0;
        
        int loopCnt = 0;
        
        while(1) {
            int value;
            if(right) {
                if(!isOver(matrix, y, x+1)) {
                    value = matrix[y][x+1];    
                    ans.push_back(value);
                    x++;
                    matrix[y][x] = -1000;
                    loopCnt = 0;
                }
                else{
                    right = false;
                    down = true;
                    loopCnt++;
                }
            }
            else if(down) {
                if(!isOver(matrix, y+1, x)) {
                    value = matrix[y+1][x];    
                    ans.push_back(value);
                    y++;
                    matrix[y][x] = -1000;
                    loopCnt = 0;
                }
                else{
                    down = false;
                    left = true;
                    loopCnt++;
                }
            }
            else if(left) {
                if(!isOver(matrix, y, x-1)) {
                    value = matrix[y][x-1];    
                    ans.push_back(value);
                    x--;
                    matrix[y][x] = -1000;
                    loopCnt = 0;
                }
                else{
                    left = false;
                    up = true;
                    loopCnt++;
                }
            }
            else if(up) {
                // break;
                if(!isOver(matrix, y-1, x)) {
                    value = matrix[y-1][x];    
                    ans.push_back(value);
                    y--;
                    matrix[y][x] = -1000;
                    loopCnt = 0;
                }
                else{
                    up = false;
                    right = true;
                    loopCnt++;
                }
            }
            
            if(loopCnt > 1) {
                break;
            }
            
            
            
        }
        
        
        return ans;
    }
};