#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

#include "Customer.h"
#include "Cellphone.h"

using namespace std;

void createStack(stack<Cellphone*, vector<Cellphone*>>&);

void buyPhone(stack<Cellphone*, vector<Cellphone*>>& cellphones, deque<Customer*>&);

void checkout(deque<Customer*> &customers);

int main() {
    const int BUY_PHONE = 1;
    const int CUSTOMER_CHECKOUT = 2;
    const int QUIT = 3;
    const string menu = "1. Buy Phone\n"
                        "2. Check out\n"
                        "3. Quit\n";
    
    stack<Cellphone*, vector<Cellphone*>> cellphones;
    deque<Customer*> customers;
    createStack(cellphones);
    
    int input;
    do {
        cout << menu;
        cout << "Enter a menu choice";
        cin >> input;
        while (input < BUY_PHONE || input > QUIT) {
            if (cellphones.empty()) { //prevents case 1 if stack is empty
                cout << "Invalid Choice! Enter a number between " << CUSTOMER_CHECKOUT << " and " << QUIT;
                cin >> input;
            } else {
                cout << "Invalid choice! Enter a number between " << BUY_PHONE << " and " << QUIT;
                cin >> input;
            }
        }
        switch (input) {
            case BUY_PHONE: {
                buyPhone(cellphones, customers);
                break;
            }
            case CUSTOMER_CHECKOUT: {
                checkout(customers);
                break;
            }
            default:
            case QUIT: {
                if(!customers.empty()){
                    cout << "There are still customers in the queue";
                    break;
                }
                cout << "Thank you for using the phone purchase software";
                return 0;
            }
        }
    } while (input != QUIT);
    cout << "Thank you for using the phone purchase software";
    return 0;
}

void checkout(deque<Customer*>& customers) {
    if(customers.empty()){
        cout << "Error, there are no customers in the queue";
        return;
    }
    Customer* c = customers.back();
    cout << c;
    customers.pop_back();
    delete c;
}

void buyPhone(stack<Cellphone*, vector<Cellphone*>>& cellphones, deque<Customer*>& customers){
    const int MAX_PHONES = 6;
    string customerName;
    int numberOfPhonesPurchased;
    cout << "Enter tha name of the customer: ";
    cin >> customerName;
    cout << "Enter the number of phones";
    cin >> numberOfPhonesPurchased;
    while(numberOfPhonesPurchased < 1 || numberOfPhonesPurchased > MAX_PHONES || numberOfPhonesPurchased > cellphones.size()){
        cout << "Invalid input! Enter a number between 1 and " << min((unsigned long long) MAX_PHONES, cellphones.size());
        cin >> numberOfPhonesPurchased;
    }
    Cellphone** phonesPurchased = new Cellphone*[numberOfPhonesPurchased];
    for (int i = 0; i < numberOfPhonesPurchased; ++i) {
        phonesPurchased[i] = cellphones.top();
        cellphones.pop();
    }
    customers.push_back(new Customer(customerName, numberOfPhonesPurchased, phonesPurchased));
}

void createStack(stack <Cellphone*, vector<Cellphone*>>& cellphones){
    fstream* fstream1 = new fstream(R"(C:\Users\SaiKM\CLionProjects\Lab9\Cellphone.cpp)", ios::in);
    while(!fstream1->eof()){
        cellphones.push(reinterpret_cast<Cellphone*>(fstream1->get()));
    }
    fstream1->close();
}