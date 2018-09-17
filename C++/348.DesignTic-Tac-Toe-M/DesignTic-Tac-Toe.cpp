//The key point is to check if the player wins the game. This means we have to check each row, each column, and each diagonal. 
//Since the move is guaranteed to be valid, so we don't need to check is the move placed in an empty block or not.

//I mark player1 as 1, and player2 as -1. For example, in a 3x3 grid, if the sum of diagonal is 3, the player1 wins the game, and if the sum of diagonal is -3, then the player2 wins the game.

class TicTacToe {
public:
    vector<int> rows;
    vector<int> cols;
    int diagonal1;
    int diagonal2;
    int size;
        
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        rows = vector<int>(n,0);
        cols = vector<int>(n,0);
        diagonal1 = 0;
        diagonal2 = 0;
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int item = (player==1)?1:-1;
        rows[row] += item;
        cols[col] += item;
        if(row==col) diagonal1 += item;
        if(size-1-row==col) diagonal2 += item;
        
        if(rows[row]==size || cols[col]==size || diagonal1==size || diagonal2==size) return 1;
        else if(rows[row]==-size || cols[col]==-size || diagonal1==-size || diagonal2==-size) return 2;
        else return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
