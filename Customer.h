//Copyright ©2022 – Howard Community College All rights reserved; Unauthorized duplication prohibited.

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
    Customer(const std::string &customerName, int numberOfPhonesPurchased, Cellphone** cellPhones);
    Customer();
    
    const std::string &getCustomerName() const;
    
    void setCustomerName(const std::string &customerName);
    
    int getNumberOfPhonesPurchased() const;
    
    void setNumberOfPhonesPurchased(int numberOfPhonesPurchased);
    
    double getCostOfPurchase() const;
    
    Cellphone *getCellPhones() const;
    
    void findTotalCost();
    
    friend std::ostream& operator<< (std::ostream& ostream1, Customer* c);
};


#endif //LAB9_CUSTOMER_H
