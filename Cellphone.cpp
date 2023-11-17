//
// Created by SaiKM on 11/14/2023.
//

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
