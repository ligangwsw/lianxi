#ifndef MYWIDGET_H           //预处理
#define MYWIDGET_H           //预处理
#include <QWidget>
#include<QWizard>
class QErrorMessage;     //前置声明
namespace Ui {
class MyWidget;            //命名空间前置声明，使得编译速度更快，避免一个头文件中
}                         //随意包含其他头文件而产生错误，使用前置声明注意
                           //ui_mywidget.h要放在mywidget.cpp里


class MyWidget : public QWidget     //定义类，继承自QWidget
{
    Q_OBJECT             //扩展c++类的功能，必须在类开始时定义。信号和槽等必须要有

public:
    explicit MyWidget(QWidget *parent = 0);     //参数指定父窗口
    ~MyWidget();
private:
    Ui::MyWidget * ui;            //定义指针，有这句就可以使用前置声明
    QErrorMessage * errordlg;                               //添加私有对象
    QWizardPage * creatPage1();
    QWizardPage * creatPage2();
    QWizardPage * creatPage3();
private slots:                       //槽
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

};

#endif // MYWIDGET_H                       //预处理结束宏
