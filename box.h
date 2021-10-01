#ifndef BOX_H
#define BOX_H
#include <QMouseEvent>
#include <QPushButton>

enum class  boxState
{
    unclicked, clicked, exploded
};

class box : public QPushButton
{
private:
    int bombCount;
    bool bomb;
    bool flagged;
    boxState bS;
public:
    box(bool bomb, QWidget *parent = nullptr);
    void setBombCount(int n);
    void setBomb(bool b);
    bool isBomb();
    bool isFlagged();
    void flag();
    bool boxLeftClicked();
    bool boxRightClicked();
    void update();

public slots:
    void mousePressEvent(QMouseEvent *e);

};

#endif // BOX_H
