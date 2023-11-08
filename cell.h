#ifndef CELL_H
#define CELL_H


class Cell
{
    int myRank;
    int myFile;


public:
    Cell(int rank, int file);
    int getMyRank() const;
    int getMyFile() const;
};

#endif // CELL_H
