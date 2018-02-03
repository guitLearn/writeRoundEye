#ifndef MAINDLG_H
#define MAINDLG_H

#include <QWidget>

namespace Ui {
class mainDlg;
}

class mainDlg : public QWidget
{
    Q_OBJECT

public:
    explicit mainDlg(QWidget *parent = 0);
    ~mainDlg();

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    Ui::mainDlg *ui;
};

#endif // MAINDLG_H
