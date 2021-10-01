#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "box.h"

class QLabel;
class QScrollArea;
class QAction;
class QMenu;
class QMenuBar;

class mainWindow : public QMainWindow
{
    Q_OBJECT
    QAction *actStart;
    QAction *actConfig;
    QAction *actQuit;
    QMenu *mnuMines;
    QGridLayout *mineField;
    box *grid[10][10];
    int width, height;

public:
    mainWindow(QWidget *parent = nullptr);
    void setupGrid();

public slots:
    void start();
    void config();
    void quit();
    void boxLeftClicked();
    void boxRightClicked();
};

#endif // MAINWINDOW_H
