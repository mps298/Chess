#include "board.h"
#include <QPixmap>

int Board::getBoardSide() const
{
    return boardSide;
}

int Board::getCellSize() const
{
    return cellSize;
}

void Board::figureIsClicked(int file, int rank)
{

}

QPoint Board::fieldAt(const QPoint &pt) const
{
    //    QSize fs = QSize(cellSize, cellSize);
    //    int offset = fontMetrics().width('M')+4; // 'M' is the widest letter
    //    if(pt.x() < offset) return QPoint(-1,-1);
    int c = /*(*/pt.x()/cellSize;//-offset) / fs.width();
    int r = pt.y()/cellSize;///fs.height();
    if(c < 1 || c > boardSide || r < 1 || r > boardSide)
        return QPoint(-1,-1);

    return QPoint(c, r);
}

void Board::newGame()
{
    whitesGo = true;
    isCheck = false;
    isMate = false;

    if (whiteFigures.isEmpty() == false)    {   whiteFigures.clear();   }
    if (blackFigures.isEmpty() == false)    {   blackFigures.clear();   }
    if (fieldsAvailable.isEmpty() == false) {   fieldsAvailable.clear();    }

    emit newGameSignal();

    whiteFigures.push_back(Figure(Type::Rock, Color::White, _A, _1, QIcon(":/pieces/pieces/Chess_rlt45.svg")));
    whiteFigures.push_back(Figure(Type::Knight, Color::White, _B, _1, QIcon(":/pieces/pieces/Chess_nlt45.svg")));
    whiteFigures.push_back(Figure(Type::Bishop, Color::White, _C, _1, QIcon(":/pieces/pieces/Chess_blt45.svg")));
    whiteFigures.push_back(Figure(Type::Queen, Color::White,_D, _1, QIcon(":/pieces/pieces/Chess_qlt45.svg")));
    whiteFigures.push_back(Figure(Type::King, Color::White, _E, _1, QIcon(":/pieces/pieces/Chess_klt45.svg")));
    whiteFigures.push_back(Figure(Type::Bishop, Color::White, _F, _1, QIcon(":/pieces/pieces/Chess_blt45.svg")));
    whiteFigures.push_back(Figure(Type::Knight, Color::White, _G, _1, QIcon(":/pieces/pieces/Chess_nlt45.svg")));
    whiteFigures.push_back(Figure(Type::Rock, Color::White, _H, _1, QIcon(":/pieces/pieces/Chess_rlt45.svg")));

    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _A, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _B, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _C, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _D, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _E, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _F, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _G, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));
    whiteFigures.push_back(Figure(Type::Pawn, Color::White, _H, _2, QIcon(":/pieces/pieces/Chess_plt45.svg")));


    blackFigures.push_back(Figure(Type::Rock, Color::Black, _A, _8, QIcon(":/pieces/pieces/Chess_rdt45.svg")));
    blackFigures.push_back(Figure(Type::Knight, Color::Black, _B, _8, QIcon(":/pieces/pieces/Chess_ndt45.svg")));
    blackFigures.push_back(Figure(Type::Bishop, Color::Black, _C, _8, QIcon(":/pieces/pieces/Chess_bdt45.svg")));
    blackFigures.push_back(Figure(Type::Queen, Color::Black,_D, _8, QIcon(":/pieces/pieces/Chess_qdt45.svg")));
    blackFigures.push_back(Figure(Type::King, Color::Black, _E, _8, QIcon(":/pieces/pieces/Chess_kdt45.svg")));
    blackFigures.push_back(Figure(Type::Bishop, Color::Black, _F, _8, QIcon(":/pieces/pieces/Chess_bdt45.svg")));
    blackFigures.push_back(Figure(Type::Knight, Color::Black, _G, _8, QIcon(":/pieces/pieces/Chess_ndt45.svg")));
    blackFigures.push_back(Figure(Type::Rock, Color::Black, _H, _8, QIcon(":/pieces/pieces/Chess_rdt45.svg")));

    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _A, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _B, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _C, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _D, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _E, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _F, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _G, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));
    blackFigures.push_back(Figure(Type::Pawn, Color::Black, _H, _7, QIcon(":/pieces/pieces/Chess_pdt45.svg")));

    update();
}

void Board::turnBoard()
{
    qDebug()<<"turnBoardSlot works";

    for (int i = 0; i < whiteFigures.size(); i++)
    {
        whiteFigures[i].setMyRank(boardSide - whiteFigures.at(i).getMyRank() + 1);
        whiteFigures[i].setMyFile(boardSide - whiteFigures.at(i).getMyFile() + 1);
    }

    for (int i = 0; i < blackFigures.size(); i++)
    {
        blackFigures[i].setMyRank(boardSide - blackFigures.at(i).getMyRank() + 1);
        blackFigures[i].setMyFile(boardSide - blackFigures.at(i).getMyFile() + 1);
    }

    for (int i = 0; i < fieldsAvailable.size(); i++)
    {
        fieldsAvailable[i].setX(boardSide - fieldsAvailable[i].x() + 1);
        fieldsAvailable[i].setY(boardSide - fieldsAvailable[i].y() + 1);
    }

    whitesGo = !whitesGo;

    update();
}

Board::Board(QWidget *parent) : QWidget(parent)
{
    boardDarkColor = Qt::lightGray;
    boardLightColor = Qt::white;

   newGame();
}

void Board::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (int f = 1; f < boardSide + 1; f++)
    {
        for (int r = 1; r < boardSide + 1; r++)
        {
            QRect rect = QRect(QPoint(f*cellSize, r*cellSize), QSize(cellSize, cellSize));
            QColor fillColor = (f+r) % 2 ? boardDarkColor: boardLightColor;

            painter.drawRect(rect);
            painter.fillRect(rect, fillColor);

            for (const auto& figure: whiteFigures)
            {
                if (figure.getMyFile() == f && figure.getMyRank() == r)
                {
                    if (figure.getIsClicked()==true)
                    {
                        painter.fillRect(rect, QColor(255, 0, 0, 50));
                    }
                    figure.getMyIcon().paint(&painter, rect, Qt::AlignCenter);
                }
            }

            for (const auto& figure: blackFigures)
            {
                if (figure.getMyFile() == f && figure.getMyRank() == r)
                {
                    if (figure.getIsClicked()==true)
                    {
                        painter.fillRect(rect, QColor(255, 0, 0, 50));
                    }
                    figure.getMyIcon().paint(&painter, rect, Qt::AlignCenter);
                }
            }

            for (int i = 0; i < fieldsAvailable.size(); i++)
            {
                if (f == fieldsAvailable.at(i).x() && r == fieldsAvailable.at(i).y())
                {
                    painter.fillRect(rect, QColor(0, 200, 0, 50));
                    break;
                }
            }
        }
    }

    QPen boardPen(Qt::SolidLine);
    boardPen.setColor(Qt::darkGray);
    painter.setPen(boardPen);

    QRect boardRect = QRect(QPoint(cellSize, cellSize),QSize(cellSize*boardSide - 1,cellSize*boardSide - 1));

    painter.setPen(Qt::black);
    painter.drawRect(boardRect);

    painter.setFont(abcFont);

    for (int f = 0; f < boardSide + 2; f++)
    {
        for (int r = 0; r < boardSide + 2; r++)
        {
            if ((r == 0 || r == boardSide + 1) && f != 0 & f != boardSide + 1)
            {
                QRect abcRect = QRect(QPoint(f*cellSize, r*cellSize), QSize(cellSize, cellSize));

                QString abcString = whitesGo? QString('a' + f - 1): QString('h' - f  + 1);
                painter.drawText(abcRect, Qt::AlignCenter, abcString);
            }

            if ((f == 0 || f == boardSide + 1) && r != 0 & r != boardSide + 1)
            {
                QRect abcRect = QRect(QPoint(f*cellSize, r*cellSize), QSize(cellSize, cellSize));

                QString abcString = whitesGo? QString('8' - r  + 1) : QString('1' + r - 1);
                painter.drawText(abcRect, Qt::AlignCenter, abcString);
            }
        }
    }

}

void Board::mousePressEvent(QMouseEvent *event)
{
    //    if (event->button() == Qt::RightButton) {   return; }

    QPoint pt = fieldAt(event->pos());
    if (pt == QPoint(-1,-1))    {   return; }

    int file = pt.x();
    int rank = pt.y();


    qDebug()<< pt.x();
    qDebug()<< pt.y()<<"\n";

    QList<Figure>* myFigures;
    QList<Figure>* otherFigures;

    if (whitesGo)
    {
        myFigures = &whiteFigures;
        otherFigures = &blackFigures;
    }
    else
    {
        myFigures = &blackFigures;
        otherFigures = &whiteFigures;
    }


//    fieldsAvailable.clear();

    for (auto& figure: *otherFigures)
    {
        if (figure.getIsClicked() == true)
        {
            figure.setIsClicked(false);
        }
    }

    bool isClicked = false;
    Figure* clickedFigure = nullptr;

    for (auto& figure: *myFigures)
    {
        if (figure.getIsClicked()==true)
        {
            isClicked = true;
            clickedFigure = &figure;
            break;
        }
    }

    if (isClicked)
    {
        bool fieldIsAvailable = false;
        for (auto field: fieldsAvailable)
        {
            if(field.x() == file && field.y() == rank)
            {
                fieldIsAvailable = true;
                break;
            }
        }

        if (fieldIsAvailable == false)
        {
            return;
        }
        else
        {
            if (clickedFigure)
            {
                clickedFigure->setMyFile(file);
                clickedFigure->setMyRank(rank);
            }

            for (int i = 0; i < otherFigures->size(); i++)
            {
                if (otherFigures->at(i).getMyFile() == file && otherFigures->at(i).getMyRank() == rank)
                {
                    emit figureIsCaptured (otherFigures->at(i));
                    otherFigures->removeAt(i);
                }
            }
            for (auto figure: *myFigures)
            {
                figure.setIsClicked(false);
            }
            fieldsAvailable.clear();
            turnBoard();
        }
    }

    else
    {
        for (auto& figure: *myFigures)
        {
            if (figure.getMyFile() == file && figure.getMyRank() == rank)
            {
                //            for (auto& fig: *myFigures)
                //            {
                //                if (fig.getIsClicked()==true && !(fig.getMyFile() == file && fig.getMyRank() == rank))
                //                {
                //                    fig.setIsClicked(false);
                //                    break;}
                //            }

                figure.setIsClicked(/*!figure.getIsClicked()*/true);

                if (figure.getIsClicked())
                {
                    fieldsAvailable = figure.getFieldsAvailable(*myFigures, *otherFigures, boardSide, false);
                }
                else
                {
                    fieldsAvailable = QVector<QPoint>();
                }

                if (fieldsAvailable == QVector<QPoint>())
                {
                    figure.setIsClicked(false);
                }

                qDebug()<<fieldsAvailable;

                break;
            }
        }
    }
    update();
}

void Board::mouseReleaseEvent(QMouseEvent *event)
{
}

void Board::mouseDoubleClickEvent(QMouseEvent *event)
{
}


void Board::resizeEvent(QResizeEvent *event)
{
    int currentBoardSize = std::min(width(), height());
    cellSize = currentBoardSize / (boardSide + 2);
    abcFont.setPixelSize(cellSize/3);

    update();
}
