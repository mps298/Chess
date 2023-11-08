#include "cell.h"

int Cell::getMyRank() const
{
    return myRank;
}

int Cell::getMyFile() const
{
    return myFile;
}

Cell::Cell(int rank, int file)
{
    myFile = file;
    myRank = rank;
}
