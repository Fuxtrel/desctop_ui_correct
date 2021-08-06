#include "check_fields.h"

bool CheckFields::checkEmail(QLineEdit *field) {
    int count_signature = 0;
    for (int i = 0; i < field->text().length(); i++) {
        if (field->text()[i] == '@' || field->text()[i] == '.') {
            count_signature++;
        }
    }
    if (count_signature < 2) {
        qDebug() << "Not enough signature '.' or '@'";
        return false;
    }
    if (field->text()[field->text().length() - 3] != '.' && field->text()[field->text().length() - 4] != '.') {
        qDebug() << "Isn't signature in domen";
        return false;
    }
    return true;
}

bool CheckFields::checkPassword(QLineEdit *field) {
    if (field->text().length() < 7) {
        return false;
    } else {
        return true;
    }
}

CheckFields::CheckFields(QLineEdit *email, QLineEdit *password) {
    is_email_password_correct = false;
    if (checkEmail(email)) {
        if (checkPassword(password)) {
            is_email_password_correct = 0;
        }else {
            is_email_password_correct = 2;
        }
    } else if (checkPassword(password)) {
        is_email_password_correct = 1;
    } else {
        is_email_password_correct = 3;
    }


}

int CheckFields::isEmailPasswordCorrect() {
    return is_email_password_correct;
}

CheckFields::CheckFields(QLineEdit *fio, QLineEdit *email, QLineEdit *password) {
    is_email_password_correct = false;
    result = "123";
    if(!checkFio(fio)){
        result[0] = '1';
    }else {
        result[0] = '0';
    }
    if(!checkEmail(email)){
        result[1] = '2';
    }else{
        result[1] = '0';
    }
    if(!checkPassword(password)){
        result[2] = '3';
    }else{
        result[2] = '0';
    }
}

bool CheckFields::checkFio(QLineEdit *fio) {
    if(fio->text().isEmpty()){
        return false;
    }
    return true;
}

QString CheckFields::isFioEmailPasswordCorrect() {
    return result;
}
