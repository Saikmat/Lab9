//Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.

#include "Cellphone.h"

const std::string &Cellphone::getCellphoneIdNumber() const {
    return cellphoneIDNumber;
}

void Cellphone::setCellphoneIdNumber(const std::string &cellphoneIdNumber) {
    cellphoneIDNumber = cellphoneIdNumber;
}

const std::string &Cellphone::getCellphoneNumber() const {
    return cellphoneNumber;
}

void Cellphone::setCellphoneNumber(const std::string &cellphoneNumber) {
    Cellphone::cellphoneNumber = cellphoneNumber;
}

Cellphone::Cellphone(std::string cellPhoneIDNumber, std::string cellphoneNumber) {
    this->cellphoneIDNumber = cellPhoneIDNumber;
    this->cellphoneNumber = cellphoneNumber;
}

Cellphone::Cellphone() {
    cellphoneIDNumber = "none";
    cellphoneNumber = "none";
}
