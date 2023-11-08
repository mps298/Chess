#ifndef FIGURE_H
#define FIGURE_H



#include <QIcon>
#include <QDebug>

const int _A = 1;
const int _B = 2;
const int _C = 3;
const int _D = 4;
const int _E = 5;
const int _F = 6;
const int _G = 7;
const int _H = 8;

const int _1 = 8;
const int _2 = 7;
const int _3 = 6;
const int _4 = 5;
const int _5 = 4;
const int _6 = 3;
const int _7 = 2;
const int _8 = 1;



enum class Type {King, Queen, Rock, Bishop, Knight, Pawn};
enum class Color {White,Black};

class Figure
{
    Type myType;
    Color myColor;

    QIcon myIcon;

    bool isClicked;

    int myRank;
    int myFile;

public:
    Figure();
    Figure(Type Type, Color color, int file, int rank, QIcon icon);
    Type getMyType() const;
    void setMyType(const Type &value);
    Color getMyColor() const;
    void setMyColor(const Color &value);
    int getMyRank() const;
    void setMyRank(int value);
    int getMyFile() const;
    void setMyFile(int value);
    QIcon getMyIcon() const;
    void setMyIcon(const QIcon &value);

    bool getIsClicked() const;
    void setIsClicked(bool value);

    QVector<QPoint> getFieldsAvailable(const QList<Figure> &myFigures, const QList<Figure> otherFigures, const int boardSide, bool justChecking);

};

#endif // FIGURE_H
