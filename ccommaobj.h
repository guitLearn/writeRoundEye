#ifndef CCOMMAOBJ_H
#define CCOMMAOBJ_H

#include <QPainterPath>

class CCommaObj
{
public:
    CCommaObj();
    void paintOjb( QPainterPath &path, const QPointF &centerPoint, float radius);
};

#endif // CCOMMAOBJ_H0
