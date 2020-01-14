#include "solver.h"

solver::solver()
{

}

bool solver::solveBoard(vector<vector<int>> board) {
    int row = 0;
    int col = 0;
    tuple<int, int> found;

    found = findEmpty(board, row, col);
    if(found == make_tuple(-1,-1)) {
        printBoard(board);
        cout << "found the solution!" << endl;
        return true;
    } else {
        row = get<0>(found);
        col = get<1>(found);
    }

    for(int n = 1; n <= 9; n++){
        if(correctNum(board, row, col, n)) {
            board[row][col] = n;

//            if(solveBoard(board)) {
//                return true;
//            }
            return solveBoard(board);

            board[row][col] = UNASSIGNED;

        }
    }
    return false;
}

tuple<int, int> solver::findEmpty(vector<vector<int> > board, int startRow, int startCol) {
    for(int row = startRow; row < N; row++) {
        for(int col = startCol; col < N; col++) {
            if(board[row][col] == UNASSIGNED) {
                return {row, col};
            }
        }
    }

    return {-1, -1};
}

bool solver::usedInCol(vector<vector<int> > board, int col, int num) {
    for(int row = 0; row < N; row++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool solver::usedInRow(vector<vector<int> > board, int row, int num) {
    for(int col = 0; col < N; col++) {
        if(board[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool solver::usedInBox(vector<vector<int> > board, int boxStartRow, int colStartRow, int num) {
    for(int row = boxStartRow; row < 3; row++) {
        for(int col = colStartRow; col < 3; col++) {
            if(board[row][col] == num)
                return true;
        }
    }
    return false;
}

bool solver::correctNum(vector<vector<int> > board, int row, int col, int num) {
    if(!usedInCol(board, col, num) && !usedInRow(board, row, num) && !usedInBox(board, row - row % 3, col - col % 3, num)){
        return true;
    }

    return false;
}

void solver::printBoard(vector<vector<int> > board) {
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            cout << board[row][col] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> solver::getBoard() {
    return board;
}
