#include "gamemanager.h"
#include "mainwindow.h"
#include <QLabel>
#include <QScrollArea>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QEventLoop>
#include <QSettings>
#include <QMessageBox>
#include <QStatusBar>
#include <QCloseEvent>

gameManager::gameManager(QWidget *parent)
    :QMainWindow(parent)
{
    lblMines = new QLabel;
    lblMines->setSizePolicy(QSizePolicy::Ignored,
                            QSizePolicy::Ignored);
    lblMines->setScaledContents(true);
    scrollArea = new QScrollArea;
    scrollArea->setWidget(lblMines);
    setCentralWidget(scrollArea);

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

    w = 1024;
    h = 768;
    resize(w, h);
    setWindowTitle(tr("Minesweeper"));
    connect(actStart, SIGNAL(triggered()), this, SLOT(start()));
    connect(actConfig, SIGNAL(triggered()), this, SLOT(config()));
    connect(actQuit, SIGNAL(triggered()), this, SLOT(quit()));
    statusBar()->showMessage(tr("Ready"), 2000);
}

void gameManager::start()
{


}

void gameManager::config()
{

}

void gameManager::quit()
{
    close();
}
