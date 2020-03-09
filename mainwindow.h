#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <qsqldatabase.h>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public:
    QSqlDatabase db;
    QSqlQuery query;

private slots:
    void on_signinButton_clicked();

    void on_gotoSignup_clicked();

    void on_signupButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
