#include "box.h"
#include <QPushButton>

box::box(bool bomb, QWidget *parent):
    QPushButton(parent)
{
    bombCount = 0;
    flagged = false;
    bS = boxState::unclicked;
    setBomb(bomb);
    update();
}

void box::setBombCount(int n)
{
    if (n != 0)
        setText(QString::number(n));
}

void box::setBomb(bool b)
{
    bomb = b;
}

bool box::isBomb()
{
    return bomb;
}

bool box::isFlagged()
{
    return flagged;
}

void box::flag()
{
    if (bS == boxState::unclicked)
    {
        flagged = !flagged;
        setText(flagged ? "X" : "");
    }
}

bool box::boxLeftClicked()
{
    if (isBomb())
        bS = boxState::exploded;
    else
        bS = boxState::clicked;
    update();
    return isBomb();
}

bool box::boxRightClicked()
{
    flag();
    return isBomb();
}

void box::update()
{
    QString style = "";
    if (bS == boxState::unclicked)
    {
        if(isBomb())
            style += "QPushButton {background-color: rgb(255, 180, 180);border-style: inset;border:1px solid #666;}";
        else
            style += "QPushButton {background-color: rgb(255, 255, 255);border-style: inset;border:1px solid #666;}";
        style += "QPushButton:hover {background-color: rgb(255, 250, 214);border-style: inset;}";
        setText("");
    }
    else if (bS == boxState::clicked)
    {
        style += "QPushButton {background-color: rgb(220,220,220);border-style: inset;}";
        setEnabled(false);
    }
    else if (bS == boxState::exploded)
    {
        style += "QPushButton {background-color: rgb(255, 0, 0);border-style: inset;}";
        setEnabled(false);
    }
    setStyleSheet(style);
}

void box::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::RightButton)
        emit boxRightClicked();
    if (e->button() == Qt::LeftButton && !flagged)
        emit boxLeftClicked();
}
