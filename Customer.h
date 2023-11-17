//Copyright ©2023 – Howard Community College All rights reserved; Unauthorized duplication prohibited.

#ifndef LAB9_CUSTOMER_H
#define LAB9_CUSTOMER_H


#include <string>
#include "Cellphone.h"

class Customer {
private:
    const double COST = 199.99;
    const double SALES_TAX = 1.06;
    int numberOfPhonesPurchased;
    double costOfPurchase; // 199.99 a piece, 6% tax, hold total
    Cellphone* cellPhones;
    std::string customerName;

public:
    /*
     * Constructs customer object given name, number of items purchased, and the array of cellphones
     */
    Customer(const std::string &customerName, int numberOfPhonesPurchased, Cellphone** cellPhones);

    /*
     * Default constructor
     */
    Customer();

    /*
     * Gets customer's name
     */
    const std::string &getCustomerName() const;

    /*
     * Sets customer's name
     */
    void setCustomerName(const std::string &customerName);

    /*
     * Gets number of phones purchased
     */
    int getNumberOfPhonesPurchased() const;

    /*
     * Sets number of phones purchased
     */
    void setNumberOfPhonesPurchased(int numberOfPhonesPurchased);

    /*
     * Gets the cost of the purchase
     */
    double getCostOfPurchase() const;

    /*
     * Gets the array of cellphones
     */
    Cellphone *getCellPhones() const;

    /*
     * Find the total cost inclusive of taxes
     */
    void findTotalCost();

    /*
     * Prints the customer's receipt
     */
    friend std::ostream& operator<< (std::ostream& ostream1, Customer* c);

    /*
     * Destroys the array of cellphones in customer
     */
    ~Customer();
};


#endif //LAB9_CUSTOMER_H
