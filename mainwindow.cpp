#include "mainwindow.h"
#include <QSignalMapper>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QEventLoop>
#include <QSettings>
#include <QMessageBox>
#include <QStatusBar>
#include <QCloseEvent>
#include <QRandomGenerator>

mainWindow::mainWindow(QWidget *parent):
    QMainWindow(parent)
{
    actStart = new QAction(tr("&Start"), this);
    actStart->setToolTip(tr("Starts game"));
    actStart->setStatusTip(tr("Starts game"));

    actConfig = new QAction(tr("Configure..."), this);
    actConfig->setToolTip(tr("Opens difficulty panel"));
    actConfig->setStatusTip(tr("Opens difficulty panel"));

    actQuit = new QAction(tr("&Quit"), this);
    actQuit->setToolTip(tr("Exits game"));
    actQuit->setStatusTip(tr("Exits game"));

    mnuMines = new QMenu(tr("&Menu"), this);
    mnuMines->addAction(actStart);
    mnuMines->addAction(actConfig);
    mnuMines->addSeparator();
    mnuMines->addAction(actQuit);
    menuBar()->addMenu(mnuMines);

    mineField = new QGridLayout;
    QWidget *w = new QWidget();
    w->setLayout(mineField);

    width = 1024;
    height = 768;
    w->resize(width, height);
    w->setWindowTitle(tr("Minesweeper"));
    connect(actStart, SIGNAL(triggered()), this, SLOT(start()));
    connect(actConfig, SIGNAL(triggered()), this, SLOT(config()));
    connect(actQuit, SIGNAL(triggered()), this, SLOT(quit()));

    setupGrid();
    statusBar()->showMessage(tr("Ready"), 2000);
}

void mainWindow::setupGrid()
{
    QSignalMapper *mouseLeftMapper;
    QSignalMapper *mouseRightMapper;
    mouseLeftMapper = new QSignalMapper(this);
    mouseRightMapper = new QSignalMapper(this);
    connect(mouseLeftMapper, SIGNAL(mapped(int)), this, SLOT(boxLeftClicked()));
    connect(mouseRightMapper, SIGNAL(mapped(int)), this, SLOT(boxRightClicked()));

    for (int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
        {
            bool isBomb = (QRandomGenerator::global()->generate() > 0.2) ? false : true;
            box *b = new box(isBomb);
            grid[i][j] = b;
            b->setSizePolicy(QSizePolicy ::Expanding , QSizePolicy ::Expanding );
            b->setFocusPolicy(Qt::NoFocus);
            b->setMinimumSize(37, 37);
            b->setMaximumSize(37, 37);
            QFont font = b->font();
            font.setPointSize(18);
            b->setFont(font);
            mineField->addWidget(b, i, j);
            mouseLeftMapper->setMapping(b,(i*1000)+j);
            mouseRightMapper->setMapping(b,(i*1000)+j);
            connect(b, SIGNAL(mousePressEvent()), this, SLOT()));
        }
}

void mainWindow::start()
{


}

void mainWindow::config()
{

}

void mainWindow::quit()
{
    close();
}

void mainWindow::boxLeftClicked()
{

}

void mainWindow::boxRightClicked()
{

}
