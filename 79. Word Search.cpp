class Solution {

    bool isValid(int row, int col, int ind, vector<vector<char>>& board, string &word){
        if(row>=0 && row<board.size() && col>=0 && col<board[0].size() && 
            board[row][col] == word[ind]) 
            return true;
        return false;
    }

    bool check(int row, int col, int ind, vector<vector<char>>& board, string &word){
        if (board[row][col] == word[word.length() - 1] && ind == word.length() - 1) {
            return true;
        }

        
        char temp = word[ind];
        board[row][col] = '#';
        
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {1, 0, -1, 0};

        for(int i=0; i<4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(isValid(nrow, ncol, ind+1, board, word)){
                if( check(nrow, ncol, ind+1, board, word)) return true;
            }
        }
        board[row][col] = temp;

        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if( check(i, j, 0, board, word)) return true;
                }
            }
        }

        return false;
    }
};
