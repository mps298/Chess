#ifndef CAPTUREDWIDGET_H
#define CAPTUREDWIDGET_H

#include <QWidget>

#include <QMultiMap>
#include <QPainter>
#include <QDebug>


#include "figure.h"

class CapturedWidget : public QWidget
{
    QMultiMap <Type, QIcon> capturedWhites;
    QMultiMap <Type, QIcon> capturedBlacks;

    Q_OBJECT
public:
    explicit CapturedWidget(QWidget *parent = nullptr);

signals:

public slots:
   void addCapturedFigure (const Figure& figure);
   void clearCapturedFigures();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // CAPTUREDWIDGET_H
