// Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited.

#include <ostream>
#include <iomanip>
#include "Customer.h"
#include "Cellphone.h"

Customer::Customer(const std::string &customerName, int numberOfPhonesPurchased, Cellphone** cellPhones){
    this->customerName = customerName;
    this->numberOfPhonesPurchased = numberOfPhonesPurchased;
    for (int i = 0; i < numberOfPhonesPurchased; ++i) {
        this->cellPhones[i] = cellPhones[i];
    }
    findTotalCost();
}

Customer::Customer() {
    customerName = "none";
    costOfPurchase = 0.0;
    numberOfPhonesPurchased = 1;
    cellPhones[0] = new Cellphone();
}

const std::string &Customer::getCustomerName() const {
    return customerName;
}

void Customer::setCustomerName(const std::string &customerName) {
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
    return *cellPhones;
}

void Customer::findTotalCost() {
    costOfPurchase = COST * numberOfPhonesPurchased * SALES_TAX;
    
}

std::ostream &operator<<(std::ostream &ostream1, Customer *c) {
    int costLength = 5 + (c->getCostOfPurchase() > 1000);
    return ostream1 << std::setprecision(costLength)
                    << "Receipt"
                    << "\nCustomer name: " << c->getCustomerName()
                    << "\nNumber of Phones: " << c->getNumberOfPhonesPurchased()
                    << "\nTotal amount due: $" << c->getCostOfPurchase() << std::endl;
}

