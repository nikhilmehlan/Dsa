class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int row, int col, int index, int m, int n) {
 
        if (index == word.length()) {
            return true;
        }
     
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[index]) {
            return false;
        }
        
        char temp = board[row][col];
        board[row][col] = '!';
   
        bool top = search(board, word, row - 1, col, index + 1, m, n);
        bool right = search(board, word, row, col + 1, index + 1, m, n);
        bool bottom = search(board, word, row + 1, col, index + 1, m, n);
        bool left = search(board, word, row, col - 1, index + 1, m, n);
        
        // Restore the cell value after exploring all possibilities
        board[row][col] = temp;
        
      
        return top || right || bottom || left;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
       
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (search(board, word, i, j, 0, m, n)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
