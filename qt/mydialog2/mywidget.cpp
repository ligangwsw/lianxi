#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>

MyWidget::MyWidget(QWidget *parent):    //构造函数，名与类名相同，
                                       //用于为某些成员变量设置初始值
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);

}

MyWidget::~MyWidget()                    //析构函数
{
    delete ui;
}


QWizardPage * MyWidget::creatPage1()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}
QWizardPage * MyWidget::creatPage2()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}
QWizardPage * MyWidget::creatPage3()
{
    QWizardPage *page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}






void MyWidget::on_pushButton_clicked()
{
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color=dialog.currentColor();
    qDebug()<<"color:"<<color;
    //ui->lineEdit->text(
}

void MyWidget::on_pushButton_5_clicked()
{
    QString fileName=QFileDialog::getOpenFileName(this,tr("文件对话框"),
                                                  "D:",tr("图片文件（*png *jpg）"));
            qDebug()<<"fileName:"<<fileName;
}

void MyWidget::on_pushButton_2_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)ui->pushButton_2->setFont(font);
    else qDebug()<<tr("没有选择字体！");
}

void MyWidget::on_pushButton_6_clicked()
{
    bool ok;
    QString string=QInputDialog::getText(this,tr("输入字符串对话框"),
                     tr("请输入用户名："),QLineEdit::Normal,tr("admin"),&ok);
    if(ok)qDebug()<<"string:"<<string;
    int value1=QInputDialog::getInt(this,tr("输入整数对话框"),
                                    tr("请输入-1000到1000之间的数值"),100,-1000,1000,10,&ok);
    if(ok)qDebug()<<"value1:"<<value1;
    double value2 = QInputDialog::getDouble(this,tr("输入浮点数对话框"),
                     tr("请输入-1000到1000之间的数值"),0.00,-1000,1000,2,&ok);
    if(ok)qDebug()<<"value2:"<<value2;
    QStringList items;
    items << tr("条目1")<< tr("条目2");
    QString item =QInputDialog::getItem(this,tr("输入条目对话框"),tr("请选项或输入一个条目"),items,0,false,&ok);
    if(ok) qDebug()<<"item:"<<item;
}

void MyWidget::on_pushButton_3_clicked()
{
    int ret1 = QMessageBox::question(this,tr("问题对话框"),tr("你了解qt吗？"),QMessageBox::Yes,QMessageBox::No);
    int ret2 = QMessageBox::information(this,tr("提示对话框"),tr("这是qt书籍"),QMessageBox::Ok);
    int ret3 = QMessageBox::warning(this,tr("警告对话框"),tr("不能提前结束"),QMessageBox::Abort);
    int ret4 = QMessageBox::critical(this,tr("严重错误对话框"),tr("发现一个严重错误，现在要关闭所有文件"),QMessageBox::YesAll);
    QMessageBox::about(this,tr("关于对话框"),tr("can you do what i can do"));
}

void MyWidget::on_pushButton_7_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"),tr("取消"),0,5000,this);
    dialog.setWindowTitle(tr("进度对话框"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0;i<5000;i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled())break;
    }
    dialog.setValue(50000);
    qDebug()<<tr("复制结束");
}

void MyWidget::on_pushButton_4_clicked()
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("这里是出错信息"));
}

void MyWidget::on_pushButton_8_clicked()
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(creatPage1());
    wizard.addPage(creatPage2());
    wizard.addPage(creatPage3());
    wizard.exec();
}
