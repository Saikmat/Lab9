/*
 * Copyright ©2024 – Howard Community College All rights reserved; Unauthorized duplication prohibited.
 * Name: Sai Matukumalli
 * Program Name: Cellphone checkout software
 * Program Description: This program maintains a checkout system for cellphones, tracking how many people have a phone, how many people are customers, and who has what phones
 */


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

void printCopyright();

int validateInput(const string &menu, const stack<Cellphone *, vector<Cellphone *>> &cellphones, int input);
const int DEFAULT = 0;
const int BUY_PHONE = 1;
const int CUSTOMER_CHECKOUT = 2;
const int QUIT = 3;

/*
 * Runs the program
 */
int main() {
    printCopyright();

    const string menu = "\n1. Buy Phone\n"
                        "2. Check out\n"
                        "3. Quit\n";
    
    stack<Cellphone*, vector<Cellphone*>> cellphones;
    deque<Customer*> customers;
    createStack(cellphones);
    
    int input = DEFAULT;

    while (input != QUIT){
        cout << menu;
        cout << "Enter a menu choice";
        cin >> input;
        input = validateInput(menu, cellphones, input);
        switch (input) { // NOLINT(*-multiway-paths-covered)
            case BUY_PHONE: {
                buyPhone(cellphones, customers);
                break;
            }
            case CUSTOMER_CHECKOUT: {
                checkout(customers);
                break;
            }
            case QUIT: {
                if(!customers.empty()){
                    cout << "There are still " << customers.size() << " customers in the queue" << endl;
                    input = DEFAULT;
                    break;
                }
                cout << "Thank you for using the phone purchase software";
                return 0;
            }
        }
    }
    cout << "Thank you for using the phone purchase software";
    return 0;
}

/*
 * Checks if the menu input is valid and makes sure that the user enters a value that is actually contained in the inputs
 * Also prevents the user from entering the buy menu when the stack is empty
 */
int validateInput(const string &menu, const stack<Cellphone *, vector<Cellphone *>> &cellphones, int input) {
    while (input < BUY_PHONE || input > QUIT) {
        cout << "Invalid choice! Enter a number between " << BUY_PHONE << " and " << QUIT;
        cout << menu;
        cin >> input;
    }
    while(input == BUY_PHONE && cellphones.empty()){
        cout << "There are no more phones for purchase! Enter a number between " << CUSTOMER_CHECKOUT << " and " << QUIT;
        cout << menu;
        cin >> input;
    }

    return input;
}

/*
 * Prints the receipt of the customer at the front of the parameter deque
 * No return since the print is done in the menu
 */
void checkout(deque<Customer*>& customers) {
    if(customers.empty()){
        cout << "Error, there are no customers in the queue";
        return;
    }
    Customer* c = customers.front();
    customers.pop_front();
    cout << c;
    delete c;
}

/*
 * Allows the customer to buy a phone
 * Takes in a stack of cellphones that are available and the customer deque to push customers onto
 * Pops a user entered number phones off the stack and into the customer's "shopping cart" so they can check out
 * No return, all data is modified in the method itself
 */
void buyPhone(stack<Cellphone*, vector<Cellphone*>>& cellphones, deque<Customer*>& customers){
    string customerName;
    int numberOfPhonesPurchased = 0;
    cout << "Enter the name of the customer: ";
    cin.ignore();
    getline(cin, customerName);
    cout << "Enter the number of phones: ";
    cin >> numberOfPhonesPurchased;
    while(numberOfPhonesPurchased < 1 || numberOfPhonesPurchased > 6 || numberOfPhonesPurchased > cellphones.size()){
        cout << "Not Enough Phones! Enter a number between 1 and " << min((unsigned long long) 6, cellphones.size());
        cin >> numberOfPhonesPurchased;
    }
    Cellphone* phonesPurchased[numberOfPhonesPurchased];

    for (int i = 0; i < numberOfPhonesPurchased; ++i) {
        phonesPurchased[i] = cellphones.top();
        cellphones.pop();
    }
    customers.push_back(new Customer(customerName, numberOfPhonesPurchased, phonesPurchased));
}

/*
 * Reads the text file of all the cellphones and creates a stack of cellphone objects given the ID and phone number
 * No return, the stack is modified in place
 */
void createStack(stack <Cellphone*, vector<Cellphone*>>& cellphones){
    ifstream* ifstream1 = new ifstream(R"(C:\Users\SaiKM\CLionProjects\Lab9\Cellphone.txt)", ios::in);
    while(!ifstream1->eof()){
        string phoneID, phoneNumber;
        getline(*ifstream1, phoneID);
        getline(*ifstream1, phoneNumber);
        cellphones.push(new Cellphone(phoneID, phoneNumber));
    }
    ifstream1->close();
    delete ifstream1;
}

/*
 * Prints the HCC copyright
 */
void printCopyright(){
    cout << "\n\nCopyright ©2023 – Howard Community College All rights reserved; Unauthorized duplication prohibited.\n\n\n\n";
}