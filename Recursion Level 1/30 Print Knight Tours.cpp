#include<bits/stdc++.h>

using namespace std;

void displayBoard(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightTour(vector<vector<int>> board, int r, int c, int move) {
    if (r < 0 || c < 0 || r >= board.size() || c >= board.size() || board[r][c] != 0) {
        return;
    }
    if (move == board.size() * board.size()) {
        board[r][c] = move;
        displayBoard(board);
        board[r][c] = 0;
        return;
    }
    board[r][c] = move;
    printKnightTour(board, r-2, c+1, move + 1);
    printKnightTour(board, r-1, c+2, move + 1);
    printKnightTour(board, r+2, c+1, move + 1);
    printKnightTour(board, r+1, c+2, move + 1);
    printKnightTour(board, r-2, c-1, move + 1);
    printKnightTour(board, r-1, c-2, move + 1);
    printKnightTour(board, r+2, c-1, move + 1);
    printKnightTour(board, r+1, c-2, move + 1);
    board[r][c] = 0;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int> (n, 0));
    int r, c;
    cin >> r >> c;
    printKnightTour(board, r, c, 1);
}