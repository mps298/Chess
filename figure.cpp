#include "figure.h"

Type Figure::getMyType() const
{
    return myType;
}

void Figure::setMyType(const Type &value)
{
    myType = value;
}

Color Figure::getMyColor() const
{
    return myColor;
}

void Figure::setMyColor(const Color &value)
{
    myColor = value;
}

int Figure::getMyRank() const
{
    return myRank;
}

void Figure::setMyRank(int value)
{
    myRank = value;
}

int Figure::getMyFile() const
{
    return myFile;
}

void Figure::setMyFile(int value)
{
    myFile = value;
}

QIcon Figure::getMyIcon() const
{
    return myIcon;
}

void Figure::setMyIcon(const QIcon &value)
{
    myIcon = value;
}

bool Figure::getIsClicked() const
{
    return isClicked;
}

void Figure::setIsClicked(bool value)
{
    isClicked = value;
}

QVector<QPoint> Figure::getFieldsAvailable(const QList<Figure> &myFigures, const QList<Figure> otherFigures, const int boardSide, bool justChecking)
{
    //    if(justChecking == true && myType == Type::King)
    //    {
    //        return QVector<QPoint>();
    //    }

    QVector<QPoint> fieldsAvailable;

    bool isAvailable = true;

    switch (myType) {
    case Type::King:
    {
        if (myFile - 1 > 0 && myRank - 1 > 0) // top-left
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank - 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank - 1));
            }

            isAvailable = true;
        }
        if (myFile - 1 > 0) // left
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank));
            }

            isAvailable = true;
        }
        if (myFile - 1 > 0 && myRank + 1 <= boardSide) // bottom-left
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank + 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank + 1));
            }

            isAvailable = true;
        }
        if (myRank + 1 <= boardSide) // bottom
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile && piece.getMyRank() == myRank + 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile, myRank + 1));
            }

            isAvailable = true;
        }
        if (myFile + 1 <= boardSide && myRank + 1 <= boardSide) // bottom-right
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank + 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank + 1));
            }

            isAvailable = true;
        }
        if (myFile + 1 <= boardSide) // right
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank));
            }

            isAvailable = true;
        }
        if (myFile + 1 <= boardSide && myRank - 1 > 0) // top-right
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank - 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank - 1));
            }

            isAvailable = true;
        }
        if (myRank - 1 > 0) // top
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile && piece.getMyRank() == myRank - 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile, myRank - 1));
            }

            isAvailable = true;
        }

        if (justChecking == false)
        {
            QVector<QPoint> attackedFields;
            for (auto piece: otherFigures)
            {
                attackedFields += piece.getFieldsAvailable(otherFigures, myFigures, boardSide, true);
            }
            qDebug()<<"attacked before: "<<attackedFields;
//            std::unique(attackedFields.begin(), attackedFields.end());
//            qDebug()<<"attacked after: "<<attackedFields;

            for (int i = 0; i < attackedFields.size(); i++)
            {
                for (int j = 0; j < fieldsAvailable.size(); j++)
                {
                    if (attackedFields.at(i) == fieldsAvailable.at(j))
                    {
                        fieldsAvailable.remove(j);
                        break;
                    }
                }
            }
        }

        break;
    }
    case Type::Pawn:
    {
        if (justChecking == false)
        {
            if (myRank - 1 > 0) // short move
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == myFile && piece.getMyRank() == myRank - 1)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(myFile, myRank - 1));
                }

                isAvailable = true;
            }

            if (myRank == _2) //long pawn move
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == myFile && piece.getMyRank() == myRank - 2)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(myFile, myRank - 2));
                }
            }

            isAvailable = false;

            if (myFile + 1 <= boardSide && myRank - 1 > 0) // top-right
            {
                for (auto piece: otherFigures)
                {
                    if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank - 1)
                    {
                        isAvailable = true;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(myFile + 1, myRank - 1));
                }

                isAvailable = false;
            }

            if (myFile - 1 > 0 && myRank - 1 > 0) // top-left
            {
                for (auto piece: otherFigures)
                {
                    if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank - 1)
                    {
                        isAvailable = true;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(myFile - 1, myRank - 1));
                }

                isAvailable = false;
            }
        }
        else
        {
            qDebug()<<"just checking";
            if (myFile + 1 <= boardSide && myRank + 1 <= boardSide)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank + 1));
            }
            if (myFile - 1 > 0 && myRank + 1 <= boardSide)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank + 1));
            }
        }


        break;
    }
    case Type::Rock:
    {
        bool isAvailable = true;

        int rank = myRank;
        int file = myFile;

        //upwards
        do
        {
            rank--;
            if (rank > 0) // top
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }


        }
        while (isAvailable);

        isAvailable = true;
        rank = myRank;

        //downwards
        do
        {
            rank++;
            if (rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        rank = myRank;

        //leftwards
        do
        {
            file--;
            if (file > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;

        //rightwards
        do
        {
            file++;
            if (file <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        break;
    }
    case Type::Queen:
    {
        bool isAvailable = true;

        int rank = myRank;
        int file = myFile;

        //upwards
        do
        {
            rank--;
            if (rank > 0) // top
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }


        }
        while (isAvailable);

        isAvailable = true;
        rank = myRank;

        //downwards
        do
        {
            rank++;
            if (rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        rank = myRank;

        //leftwards
        do
        {
            file--;
            if (file > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;

        //rightwards
        do
        {
            file++;
            if (file <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;

        //bottom-right
        do
        {
            file++;
            rank++;
            if (file <= boardSide && rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //top-left
        do
        {
            file--;
            rank--;
            if (file > 0 && rank > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //top-right
        do
        {
            file++;
            rank--;
            if (file <= boardSide && rank > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //bottom-left
        do
        {
            file--;
            rank++;
            if (file > 0 && rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);


        break;
    }
    case Type::Bishop:
    {
        bool isAvailable = true;

        int rank = myRank;
        int file = myFile;

        //bottom-right
        do
        {
            file++;
            rank++;
            if (file <= boardSide && rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //top-left
        do
        {
            file--;
            rank--;
            if (file > 0 && rank > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //top-right
        do
        {
            file++;
            rank--;
            if (file <= boardSide && rank > 0)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);

        isAvailable = true;
        file = myFile;
        rank = myRank;

        //bottom-left
        do
        {
            file--;
            rank++;
            if (file > 0 && rank <= boardSide)
            {
                for (auto piece: myFigures)
                {
                    if (piece.getMyFile() == file && piece.getMyRank() == rank)
                    {
                        isAvailable = false;
                        break;
                    }
                }
                if (isAvailable)
                {
                    fieldsAvailable.append(QPoint(file, rank));

                    for (auto piece: otherFigures)
                    {
                        if (piece.getMyFile() == file && piece.getMyRank() == rank)
                        {
                            isAvailable = false;
                            break;
                        }
                    }
                }
            }
            else
            {
                isAvailable = false;
            }
        }
        while (isAvailable);


        break;
    }
    case Type::Knight:
    {
        if (myFile - 1 > 0 && myRank - 2 > 0)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank - 2)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank - 2));
            }
        }
        isAvailable = true;

        if (myFile - 1 > 0 && myRank + 2 <= boardSide)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 1 && piece.getMyRank() == myRank + 2)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 1, myRank + 2));
            }
        }
        isAvailable = true;

        if (myFile - 2 > 0 && myRank + 1 <= boardSide)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 2 && piece.getMyRank() == myRank + 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 2, myRank + 1));
            }
        }
        isAvailable = true;

        if (myFile - 2 > 0 && myRank - 1 > 0)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile - 2 && piece.getMyRank() == myRank - 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile - 2, myRank - 1));
            }
        }
        isAvailable = true;

        if (myFile + 1 <= boardSide && myRank + 2 <= boardSide)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank + 2)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank + 2));
            }
        }
        isAvailable = true;

        if (myFile + 1 <= boardSide && myRank - 2 > 0)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 1 && piece.getMyRank() == myRank - 2)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 1, myRank - 2));
            }
        }
        isAvailable = true;

        if (myFile + 2 <= boardSide && myRank + 1 <= boardSide)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 2 && piece.getMyRank() == myRank + 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 2, myRank + 1));
            }
        }
        isAvailable = true;

        if (myFile + 2 <= boardSide && myRank - 1 > 0)
        {
            for (auto piece: myFigures)
            {
                if (piece.getMyFile() == myFile + 2 && piece.getMyRank() == myRank - 1)
                {
                    isAvailable = false;
                    break;
                }
            }
            if (isAvailable)
            {
                fieldsAvailable.append(QPoint(myFile + 2, myRank - 1));
            }
        }

        break;
    }
    }

    return fieldsAvailable;
}


Figure::Figure()
{

}

Figure::Figure(Type type, Color color, int file, int rank, QIcon icon)
{
    myType = type;
    myColor = color;
    myRank = rank;
    myFile = file;
    myIcon = icon;
    isClicked = false;
}
