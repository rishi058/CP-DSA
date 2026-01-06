#include<bits/stdc++.h>
using namespace std; 

/*
| Board type              | Outcome with perfect play |
| ----------------------- | ------------------------- |
| Odd × odd (e.g., 3×3)   | First player win          |
| Even × even (e.g., 4×4) | Draw                      |
| Odd × even              | Depends on win condition  |

NOTE: Diagonal win doesn't mean it should always touch both corner,
(corner & edge | edge & edge) is also considered diagonal win.
e.g : 
X . . .
. X . .
. . X .

*/

class Board {
    int n, m;
    vector<vector<char>> board;
public:
    Board(int n, int m){
        board = vector<vector<char>>(n, vector<char>(m, ' '));
        this->n = n;
        this->m = m;
    }

    bool placeMark(int row, int col, char player) {
        if (row < 0 || row >= n || col < 0 || col >= m || board[row][col] != ' ') {
            return false; // Invalid move
        }
        board[row][col] = player;
        return true;
    }

    bool check_win(int row, int col){
        char player = board[row][col];
        // Check row
        bool win = true;
        for(int j = 0; j < m; j++){
            if(board[row][j] != player){
                win = false;
                break;
            }
        }
        if(win){return 1;}

        // Check column
        win = true;
        for(int i = 0; i < n; i++){
            if(board[i][col] != player){
                win = false;
                break;
            }
        }
        if(win){return 1;}

        // checking \ diagonal
        win = true;
        int r = row, c = col, ct = min(n,m)+1;
        while(r >= 0 && c >= 0){
            if(board[r][c] != player){
                win = false;
                break;
            }
            r--; c--, ct--;
        }

        if(win && (r==-1 || c==-1)){  // diagonal reaches top or left edge
            r = row; c = col;
            while(r < n && c < m){
                if(board[r][c] != player){
                    win = false;
                    break;
                }
                r++; c++; ct--;
            }
        }
        
        if(win && (r==n || c==m) && ct==0){return 1;}  // diagonal reaches bottom or right edge

        // checking / diagonal
        win = true;
        r = row; c = col, ct = min(n,m)+1;
        while(r >= 0 && c < m){
            if(board[r][c] != player){
                win = false;
                break;
            }
            r--; c++; ct--;
        }

        if(win && (r==-1 || c==m)){  // diagonal reaches top or right edge
            r = row; c = col;
            while(r < n && c >= 0){
                if(board[r][c] != player){
                    win = false;
                    break;
                }
                r++; c--; ct--;
            }
        }

        if(win && (r==n || c==-1) && ct==0){return 1;} // diagonal reaches bottom or left edge
        
        return 0;
    }
};

int main(){

    int n, m;
    cout << "Enter board dimensions (n m).\nConstraints: [1 <= n, m <= 1e6, n*m <= 1e6] : ";
    cin >> n >> m;
    Board game(n, m);
    int total_moves = n*m;

    while(1){
        cout << "\nPlayer X, Enter row and column to place your mark: "; 

        int rowX, colX;
        cin >> rowX >> colX;
        while(!game.placeMark(rowX, colX, 'X')){
            cout << "\nInvalid move! Try again: ";
            cin >> rowX >> colX;
        }

        if(game.check_win(rowX, colX)){cout<<"\nPlayer X wins!"; break;}

        if(--total_moves==0){cout<<"\nIt's a draw!";break;}   

        cout<<"\nPlayer O, Enter row and column to place your mark: ";
        int rowO, colO;
        cin >> rowO >> colO;
        while(!game.placeMark(rowO, colO, 'O')){
            cout << "\nInvalid move! Try again: ";
            cin >> rowO >> colO;
        }

        if(game.check_win(rowO, colO)){cout<<"\nPlayer O wins!"; break;}
        
        if(--total_moves==0){cout<<"\nIt's a draw!"; break;}   
    }

    return 0;
}

/*
Time compexity: After every move its a O(2*(n+m)) operation to check win condition, round off to O(n+m)

Space complexity: O(n*m) for board storage
*/