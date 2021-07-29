class Solution {

private:
    vector<vector<int>> board;
    int m,n;
    
public:
    
    Solution():
        board(200, vector<int> (200, -1)) {}
    
    
    
    void setRow(int r) {
        for(int i=0 ; i<n ; i++) {
            board[r][i] = 0;
        }
    }
    void setCol(int c) {
        for(int i=0 ; i<m ; i++) {
            board[i][c] = 0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        
        
        cout << m << ", " << n << endl;
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                if(matrix[i][j] == 0) {
                    setRow(i);
                    setCol(j);
                }
                else{
                    if(board[i][j] == -1) {
                        board[i][j] = matrix[i][j];    
                    }
                    
                }
            }
        }
        
        for(int i=0 ; i<m ; i++) {
            for(int j=0 ; j<n ; j++) {
                matrix[i][j] =  board[i][j];
            }
        }
    }
};