//Copyright ©2023 – Howard Community College All rights reserved; Unauthorized duplication prohibited.

#include "Cellphone.h"

/*
 * Returns the cellphone ID number
 */
const std::string &Cellphone::getCellphoneIdNumber() const {
    return cellphoneIDNumber;
}

/*
 * Sets the Cellphone ID number to the string parameter provided
 */
void Cellphone::setCellphoneIdNumber(const std::string &cellphoneIdNumber) {
    cellphoneIDNumber = cellphoneIdNumber;
}

/*
 * Returns the cellphone number
 */
const std::string &Cellphone::getCellphoneNumber() const {
    return cellphoneNumber;
}

/*
 * Sets the cellphone number to the passed parameter
 */
void Cellphone::setCellphoneNumber(const std::string &cellphoneNumber) {
    Cellphone::cellphoneNumber = cellphoneNumber;
}

/*
 * Constructs a cellphone object given the cellphone ID and the Cellphone number
 */
Cellphone::Cellphone(std::string cellPhoneIDNumber, std::string cellphoneNumber) {
    this->cellphoneIDNumber = cellPhoneIDNumber;
    this->cellphoneNumber = cellphoneNumber;
}

/*
 * Default constructor if no name and number are passed
 */
Cellphone::Cellphone() {
    cellphoneIDNumber = "none";
    cellphoneNumber = "none";
}

/*
 * Destructor for the cellphone object
 */
Cellphone::~Cellphone() {

}
