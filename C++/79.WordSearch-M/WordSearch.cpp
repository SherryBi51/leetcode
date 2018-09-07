//The basic idea is using DFS to scan all the possible word in the board, and check if the target exist. 
class Solution {
public:
    bool helper(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y, string &word, int start){
        //ending check
        if(start==word.size()) return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size()) return false;
        if(visited[x][y]) return false;
        if(board[x][y]==word[start]){
            //if the word[start] matches with the board[i][j]
            visited[x][y] = true;
            bool flag =  helper(board, visited, x-1, y, word, start+1) || 
                helper(board, visited, x+1, y, word, start+1) ||
                helper(board, visited, x, y-1, word, start+1) ||
                helper(board, visited, x, y+1, word, start+1);
            visited[x][y] = false;
            return flag;
        }
        else return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return true;
        if(board.size()==0 || board[0].size()==0) return false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                // Here, I define a helper function to implement the DFS. 
                if(helper(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};
