#include "capturedwidget.h"


CapturedWidget::CapturedWidget(QWidget *parent)
{
//ONLY FOR CHECKING PURPOSES, the constructor's body must be EMPTY !!!

//        Figure tmp(Type::Pawn, Color::White, 0,0, QIcon(":/pieces/pieces/Chess_plt45.svg"));
//        Figure tmp1(Type::Pawn, Color::Black,  0,0, QIcon(":/pieces/pieces/Chess_pdt45.svg"));
//        Figure tmp2(Type::Bishop, Color::White,  0,0, QIcon(":/pieces/pieces/Chess_blt45.svg"));
//        Figure tmp3(Type::Knight, Color::Black, 0,0, QIcon(":/pieces/pieces/Chess_ndt45.svg"));

//        for (int i = 0; i < 6; i++)
//        {
//            capturedWhites.insert(tmp.getMyType(), tmp.getMyIcon());
//            capturedWhites.insert(tmp2.getMyType(), tmp2.getMyIcon());
//            capturedBlacks.insert(tmp1.getMyType(), tmp1.getMyIcon());
//            capturedBlacks.insert(tmp3.getMyType(), tmp3.getMyIcon());
//        }
//        Figure tmp4(Type::Queen, Color::White, 0,0, QIcon(":/pieces/pieces/Chess_qlt45.svg"));
//        capturedWhites.insert(tmp4.getMyType(), tmp4.getMyIcon());
}

void CapturedWidget::addCapturedFigure(const Figure &figure)
{

    qDebug()<<"addCaptFigSlot works";
    if (figure.getMyColor() == Color::White)
    {
        capturedWhites.insert(figure.getMyType(), figure.getMyIcon());
    }
    else
    {
        capturedBlacks.insert(figure.getMyType(), figure.getMyIcon());
    }

    update();
}

void CapturedWidget::clearCapturedFigures()
{

    qDebug()<<"clearCaptFigSlot works";

    if (capturedWhites.isEmpty() == false)  {   capturedWhites.clear(); }
    if (capturedBlacks.isEmpty() == false)  {   capturedBlacks.clear(); }
    update();
}


void CapturedWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    const int fieldSize = 50;

    int row = 0;

    auto iterator = capturedWhites.begin();
    while (iterator!=capturedWhites.end())
    {
        int column = row<8 ? 0 : 1;
        QRect rect = QRect(QPoint(column * fieldSize, ((row+8)%8) * fieldSize), QSize(fieldSize, fieldSize));
        static_cast<QIcon>(iterator.value()).paint(&painter, rect, Qt::AlignCenter);
        ++iterator;
        row++;
    }

    row = 0;
    iterator = capturedBlacks.begin();
    while (iterator!=capturedBlacks.end())
    {
        int column = row<8 ? 2 : 3;
        QRect rect = QRect(QPoint(column * fieldSize, ((row+8)%8) * fieldSize), QSize(fieldSize, fieldSize));
        static_cast<QIcon>(iterator.value()).paint(&painter, rect, Qt::AlignCenter);
        ++iterator;
        row++;
    }
    //qDebug()<<capturedBlacks.size();
    //qDebug()<<capturedWhites.size();
}
