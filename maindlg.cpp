#include "maindlg.h"
#include "ui_maindlg.h"
#include "ccommaobj.h"
#include <QPainter>
#include <QPainterPath>

mainDlg::mainDlg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainDlg)
{
    ui->setupUi(this);
}

mainDlg::~mainDlg()
{
    delete ui;
}

void mainDlg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPainterPath path;
    float   left = 0;
    float   top = 0;
    float   radius = 10;
    QRectF  pupilRect;
    QRectF  interRect;
    QRectF  commaRect;
    QRectF  commaRectS; ///逗号小扇形曲线
    QRect   commaRectL; ///逗号大扇形曲线
    float   currentRadius = 0;
    QRect  dlgRect = this->rect();
    float   dlgCenterX = dlgRect.width() / 2;
    float   dlgCenterY = dlgRect.height() / 2;

    path.moveTo(dlgCenterX, dlgCenterY + radius * 3);
    currentRadius = radius;
    left = dlgCenterX - radius;
    top = dlgCenterY + radius;
    commaRectS.setLeft(left);
    commaRectS.setTop(top);
    commaRectS.setWidth(currentRadius * 2);
    commaRectS.setHeight(currentRadius * 2);
  //  path.arcTo(commaRectS, 270, 90);

    currentRadius = radius * 2;
    left = dlgCenterX - radius * 2;
    top = dlgCenterY - radius;
    commaRectL.setLeft(left);
    commaRectL.setTop(top);
    commaRectL.setWidth(currentRadius * 2);
    commaRectL.setHeight(currentRadius * 2);
  //  path.arcTo(commaRectL, 270, 90);



    currentRadius = radius;
    left = dlgCenterX;
    top = dlgCenterY;
    commaRect.setLeft(left);
    commaRect.setTop(top);
    commaRect.setWidth(currentRadius * 2);
    commaRect.setHeight(currentRadius * 2);
  //  path.addEllipse(commaRect);

    painter.setBrush(Qt::black);
    //painter.drawPath(path);
    //painter.drawArc(commaRectS, 270 * 16, 90 *16);
    //painter.drawArc(commaRectL, 270 * 16, 90 *16);

    QPointF startPoint;
    QPointF endPoint;
    QPointF  c1Point;
    QPointF  c2Point;
    QPainterPath path2;

   // path2.setFillRule(Qt::WindingFill);
  //  path2.moveTo(dlgCenterX + radius, dlgCenterY + radius * 2);
   // path2.arcTo(commaRectS, 0, - 90);

    //path2.arcTo(commaRectL, 270, 90);
    //path2.arcTo(commaRect, 0, 270);
    //path2.closeSubpath();

    CCommaObj commaObj;
    QPointF commaCenter(dlgCenterX + radius, dlgCenterY + radius);
    commaObj.paintOjb(path2, commaCenter, radius);
    painter.drawPath(path2);
}
