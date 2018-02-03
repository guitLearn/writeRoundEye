#include "ccommaobj.h"

CCommaObj::CCommaObj()
{

}

/**
  *绘制逗号函数
  * 参数:path - 路径对象
  *     centerPoint-逗号圆形区域的圆心
  *     radius-逗号圆形区域的半径
  * 绘制逻辑:
  *     逗号实际上由3个圆形的部分弧线组成的封闭图形
  *     1、半径为radius的圆形的四分之三部分的弧线
  *     2、半径为radius的圆形的四分之一部分的弧线
  *     3、半径为2*radius的圆形的四分之一部分的弧线
  *由于arcTo()函数会连接绘制的起始点和终点，所以需要设置起点为绘制的起点，
  *以弧线2的起点为绘制起点，绘制弧线2；
  * 然后绘制弧线3；
  * 最后绘制弧线1形成封闭弧线
  * 绘制形成的封闭区域的颜色使用的QPainter的Brush颜色
*/
void CCommaObj::paintOjb(QPainterPath &path, const QPointF &centerPoint, float radius)
{
    float centerX = centerPoint.x();
    float centerY = centerPoint.y();
    QRectF commaRect;
    QRect  commaRectS;
    QRect  commaRectL;
    float  left = 0;
    float  top = 0;
    float  currentRadius = radius;

    ///逗号的圆形区域
    left = centerX - currentRadius;
    top  = centerY - currentRadius;
    commaRect.setLeft(left);
    commaRect.setTop(top);
    commaRect.setWidth(currentRadius * 2);
    commaRect.setHeight(currentRadius * 2);

    ///逗号靠左内侧的圆形曲线区域
    currentRadius = radius;
    left = centerX - currentRadius * 2;
    top  = centerY;
    commaRectS.setLeft(left);
    commaRectS.setTop(top);
    commaRectS.setWidth(currentRadius * 2);
    commaRectS.setHeight(currentRadius * 2);

    ///逗号靠右外侧的圆形曲线区域
    currentRadius = radius * 2;
    left = centerX - radius * 3;
    top = centerY  - radius * 2;
    commaRectL.setLeft(left);
    commaRectL.setTop(top);
    commaRectL.setWidth(currentRadius * 2);
    commaRectL.setHeight(currentRadius * 2);

	path.moveTo(centerX, centerY + radius);  ///光标移到绘制起始点
    path.arcTo(commaRectS, 0, -90);
    path.arcTo(commaRectL, 270, 90);
    path.arcTo(commaRect, 0, 270);
}
