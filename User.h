#ifndef USER_H
#define USER_H

#include <QMainWindow>

class User {
public:
    int id;
    QString name;
    QString pwd;

    explicit User(QObject* parent = nullptr);
};


#endif // USER_H
