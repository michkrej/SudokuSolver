#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include "solver.h"
#include "QLabel"
#include "QTextBrowser"

static const int N = 3;
static const int UNASSIGNED = 0;


vector<vector<int>> board{{3, 1, 6},
                          {5, 2, 9},
                          {4, 8, 0}};


int main(int argc, char *argv[])
{

    solver sl;

    sl.solveBoard(sl.getBoard());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


