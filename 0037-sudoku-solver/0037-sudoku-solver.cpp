class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == ch)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board){
        int row=-1;
        int col=-1;
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    row = i;
                    col = j;
                    break;
                }

            }
            if (row!= -1) break;
        }
        if (row == -1) return true;

        for (int k=1; k<=9; k++){
            char ch = '0' + k;
            if (isValid(board, row, col, ch)){
                board[row][col] = ch;
                if (solve(board)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};