#include "maindlg.h"
#include "ui_maindlg.h"

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
