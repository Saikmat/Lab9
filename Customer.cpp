// Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited.

#include <iomanip>
#include <ostream>
#include "Customer.h"
#include "Cellphone.h"

using namespace std;

Customer::Customer(const string &customerName, int numberOfPhonesPurchased, Cellphone** cellPhones){
    this->customerName = customerName;
    this->numberOfPhonesPurchased = numberOfPhonesPurchased;
    this->cellPhones = new Cellphone[numberOfPhonesPurchased];
    for (int i = 0; i < numberOfPhonesPurchased; ++i) {
        this->cellPhones[i] = *cellPhones[i];
    }
    findTotalCost();
}

Customer::Customer() {
    customerName = "none";
    costOfPurchase = 0.0;
    numberOfPhonesPurchased = 1;
    cellPhones[0] = *new Cellphone();
}

const string &Customer::getCustomerName() const {
    return customerName;
}

void Customer::setCustomerName(const string &customerName) {
    Customer::customerName = customerName;
}

int Customer::getNumberOfPhonesPurchased() const {
    return numberOfPhonesPurchased;
}

void Customer::setNumberOfPhonesPurchased(int numberOfPhonesPurchased) {
    Customer::numberOfPhonesPurchased = numberOfPhonesPurchased;
    findTotalCost();
}

double Customer::getCostOfPurchase() const {
    return costOfPurchase;
}

Cellphone* Customer::getCellPhones() const {
    return cellPhones;
}

void Customer::findTotalCost() {
    costOfPurchase = COST * numberOfPhonesPurchased * SALES_TAX;
}

ostream &operator<<(ostream &ostream1, Customer *c) {
    c->findTotalCost();
    ostream1 << setprecision(2);
    ostream1 << "Receipt"
            << "\nCustomer name:    " << c->getCustomerName()
            << "\nNumber of Phones: " << c->getNumberOfPhonesPurchased()
            << "\nTotal amount due: $" << c->getCostOfPurchase()
            << "\n\n"
            << "Phone(s) ID and number:" << endl;
    for (int i = 0; i < c->getNumberOfPhonesPurchased(); ++i) {
        Cellphone* phone = &c->getCellPhones()[i];
        ostream1 << "ID Number: " << phone->getCellphoneIdNumber() << "\t\t\t" << "Phone Number: " << phone->getCellphoneNumber() << endl;
    }
    return ostream1;
}

