class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            if(!isValidRow(board,i) || !isValidCol(board,i))
                return false;
        }
        for(int i = 0; i<9; i+=3){
            for(int j = 0; j<9; j+=3){
                if(!isValidSubBox(board,i,j))
                    return false;
            }
        }
        return true;
    }
private:
    bool isValidSubBox(vector<vector<char>>& board, int i, int j){
        int jCopy = j;
        int iCopy = i;
        unordered_set<char> set;
        for(i = iCopy; i<iCopy+3; i++){
            for(j = jCopy; j<jCopy+3; j++){
                if(board[i][j] != '.'){
                    if(set.find(board[i][j]) != set.end())
                        return false;
                    set.insert(board[i][j]);
                }
            }
        }
        return true;
    }
    
    bool isValidRow(vector<vector<char>>& board, int i){
        unordered_set<char> set;
        for(int j = 0; j<9; j++){
            if(board[i][j] != '.'){
                if(set.find(board[i][j]) != set.end())
                    return false;
                set.insert(board[i][j]);
            }
        }
        return true;
    }
    
    bool isValidCol(vector<vector<char>>& board, int j){
        unordered_set<char> set;
        for(int i = 0; i<9; i++){
            if(board[i][j] != '.'){
                if(set.find(board[i][j]) != set.end())
                    return false;
                set.insert(board[i][j]);
            } 
        }
        return true;
    }
};
