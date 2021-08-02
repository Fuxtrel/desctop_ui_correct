#ifndef DESCTOP_NORM_CHECK_FIELDS_H
#define DESCTOP_NORM_CHECK_FIELDS_H

#include <QLineEdit>
#include <QDebug>

class CheckFields {

public:
    CheckFields(QLineEdit *email, QLineEdit *password);
    CheckFields(QLineEdit *fio, QLineEdit *email, QLineEdit *password);
    ~CheckFields() = default;
    int32_t isEmailPasswordCorrect();
    QString isFioEmailPasswordCorrect();
private:
    bool checkEmail(QLineEdit *field);
    bool checkPassword(QLineEdit *field);
    bool checkFio(QLineEdit *fio);
    int is_email_password_correct;
    QString result;
};


#endif //DESCTOP_NORM_CHECK_FIELDS_H
