#include<bits/stdc++.h>
using namespace std; 

/*
This Space Optimized logic is only suitable for Square Boards (n x n).
For Rectangular Boards (n x m), this is not able to track diagonal wins correctly.
*/

class Board {
    int n, m;
   
    int diag_count_X, diag_count_O;      // main diagonal
    int anti_diag_count_X, anti_diag_count_O; // anti-diagonal
    int diag_size; // min(n, m)

    vector<int> row_count_X, row_count_O;
    vector<int> col_count_X, col_count_O; 

public:
    Board(int n, int m){
        this->n = n;
        this->m = m;
        row_count_X = vector<int>(n, 0);
        row_count_O = vector<int>(n, 0);
        col_count_X = vector<int>(m, 0);
        col_count_O = vector<int>(m, 0);
        diag_size = min(n, m);
        diag_count_X = diag_count_O = 0;
        anti_diag_count_X = anti_diag_count_O = 0;
    }

    bool placeMark(int row, int col, char player) {
        if (row < 0 || row >= n || col < 0 || col >= m) {
            return false;
        }
        
        if(player == 'X'){
            row_count_X[row]++;
            col_count_X[col]++;
            if(row == col) diag_count_X++;
            if(row + col == diag_size - 1) anti_diag_count_X++;
        }
        else{
            row_count_O[row]++;
            col_count_O[col]++;
            if(row == col) diag_count_O++;
            if(row + col == diag_size - 1) anti_diag_count_O++;
        }
        return true;
    }

    bool check_win(int row, int col){ 
        char player = (row_count_X[row] + col_count_X[col] > row_count_O[row] + col_count_O[col]) ? 'X' : 'O';

        if(player == 'X'){
            bool row_win = row_count_X[row] == m;
            bool col_win = col_count_X[col] == n;
            bool diag_win = (diag_count_X == diag_size);
            bool anti_diag_win = (anti_diag_count_X == diag_size);
            return row_win || col_win || diag_win || anti_diag_win;
        } else {
            bool row_win = row_count_O[row] == m;
            bool col_win = col_count_O[col] == n;
            bool diag_win = (diag_count_O == diag_size);
            bool anti_diag_win = (anti_diag_count_O == diag_size);
            return row_win || col_win || diag_win || anti_diag_win;
        }
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
Time compexity: After every move its a O(1) operation to check win condition

Space complexity: O(2*(n+m)) for board storage
*/