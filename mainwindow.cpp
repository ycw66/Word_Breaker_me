#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/biancheng/qt_prj/Word_Breaker-copy/Word_Breaker_me/user.db");
    if(!db.open()) {
        QMessageBox::information(this, "异常", "服务器连接失败！");
    } else {
        QMessageBox::information(this, "成功", "成功连接服务器！");
    }
    query =QSqlQuery(db);
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

//// 登录
void MainWindow::on_signinButton_clicked()
{
    QString name = ui->userNameEdit->text();
    QString pwd = ui->userPwdEdit->text();
    //query.exec(
    if(query.exec("SELECT NAME, PWD FROM USER WHERE NAME = \'" + name + "\' AND PWD=\'" + pwd +"\'")) {
        if(query.next()) {
            QMessageBox::information(this, "消息", "登录成功");
        } else {
            QMessageBox::information(this, "消息", "用户名不存在或密码错误");
        }
    } else {
        qDebug() << "Error: Fail to query table. " << query.lastError();
        QMessageBox::information(this, "消息", "ERROR!!!");
    }
}

void MainWindow::on_gotoSignup_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_signupButton_clicked()
{
    QString name = ui->userNameEdit_2->text();
    QString pwd1 = ui->userPwdEdit_2->text();
    QString pwd2 = ui->repeatPwdEdit->text();

    if(pwd1 != pwd2) {
        QMessageBox::information(this, "消息", "您输入的密码不一致");
    } else{
        if(query.exec("SELECT NAME FROM USER WHERE NAME = \'" + name + "\'")){
            if(query.next()) {
                QMessageBox::information(this, "消息", "用户名已被注册");
            } else {
                if(query.exec("INSERT INTO USER VALUES(NULL, \'" + name + "\', \'" + pwd1 + "\')")) {
                    QMessageBox::information(this, "消息", "注册成功");
                    ui->stackedWidget->setCurrentIndex(0);
                } else {
                    QMessageBox::information(this, "消息", "注册失败");
                    qDebug() << "Error: Fail to query table. " << query.lastError();
                }
            }
        } else {
            QMessageBox::information(this, "消息", "ERROR!!!");
        }
    }
}
