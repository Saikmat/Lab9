// Copyright 2023 - Howard Community College All rights reserved; Unauthorized duplication prohibited.

#include <iomanip>
#include <ostream>
#include "Customer.h"
#include "Cellphone.h"

using namespace std;

/*
 * Constructs a customer object given the name, number of phones purchased, and the list of cellphones in their cart
 */
Customer::Customer(const string &customerName, int numberOfPhonesPurchased, Cellphone** cellPhones){
    this->customerName = customerName;
    this->numberOfPhonesPurchased = numberOfPhonesPurchased;
    this->cellPhones = new Cellphone[numberOfPhonesPurchased];
    for (int i = 0; i < numberOfPhonesPurchased; ++i) {
        this->cellPhones[i] = *cellPhones[i];
    }
    findTotalCost();
}

/*
 * Constructs a default customer with one cellphone in their cart
 */
Customer::Customer() {
    customerName = "none";
    costOfPurchase = 0.0;
    numberOfPhonesPurchased = 1;
    cellPhones[0] = *new Cellphone();
}

/*
 * Returns the customer's name
 */
const string &Customer::getCustomerName() const {
    return customerName;
}

/*
 * Sets the customer's name
 */
void Customer::setCustomerName(const string &customerName) {
    Customer::customerName = customerName;
}

/*
 * Returns the number of phones that were purchased
 */
int Customer::getNumberOfPhonesPurchased() const {
    return numberOfPhonesPurchased;
}

/*
 * Sets the number of phones to be purchased
 */
void Customer::setNumberOfPhonesPurchased(int numberOfPhonesPurchased) {
    Customer::numberOfPhonesPurchased = numberOfPhonesPurchased;
    findTotalCost();
}

/*
 * Returns the total cost of purchase
 */
double Customer::getCostOfPurchase() const {
    return costOfPurchase;
}

/*
 * Returns the array of cellphones that were purchased
 */
Cellphone* Customer::getCellPhones() const {
    return cellPhones;
}

/*
 * Find the total cost including taxes of phones for purchase
 */
void Customer::findTotalCost() {
    costOfPurchase = COST * numberOfPhonesPurchased * SALES_TAX;
}

/*
 * Overrides the ostream operator for Customer objects for ease of printing
 * Returns the full stream with receipt informationm
 */
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

/*
 * Destroys the array of cellphones
 */
Customer::~Customer() {
    delete[] cellPhones;
}

