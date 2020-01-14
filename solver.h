#ifndef SOLVER_H
#define SOLVER_H

#include "iostream"
#include "vector"
#include "tuple"

using namespace std;

class solver
{
public:
    solver();
    bool solveBoard(vector<vector<int>> board);
    tuple<int, int> findEmpty(vector<vector<int>> board, int startRow, int startCol);
    bool usedInRow(vector<vector<int>> board, int row, int num);
    bool usedInCol(vector<vector<int>> board, int col, int num);
    bool usedInBox(vector<vector<int>> board, int boxStartRow, int colStartRow, int num);
    bool correctNum(vector<vector<int>> board, int row, int col, int num);
    void printBoard(vector<vector<int>> board);

    vector<vector<int>> getBoard();

private:
    int UNASSIGNED = 0;
    int N = 3;
    vector<vector<int>> board{{3, 1, 6},
                              {5, 2, 9},
                              {4, 8, 0}};
};

#endif // SOLVER_H
