#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QList>

#include "figure.h"

class Board : public QWidget
{
    Q_OBJECT

    QColor boardDarkColor;
    QColor boardLightColor;

    const int boardSide = 8;
    int cellSize = 50;

    QFont abcFont;

    QList<Figure> whiteFigures;
    QList<Figure> blackFigures;

    QVector<QPoint> fieldsAvailable;


    bool whitesGo;
    bool isCheck;
    bool isMate;

public:
    explicit Board(QWidget *parent = nullptr);

    int getBoardSide() const;
    int getCellSize() const;

    void figureIsClicked (int file, int rank);
    QPoint fieldAt(const QPoint &pt) const;

    void newGame();


signals:
    void figureIsCaptured (const Figure& figure);
    void newGameSignal();

public slots:

    void turnBoard();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;
};

#endif // BOARD_H
