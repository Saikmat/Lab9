#ifndef LAB9_CELLPHONE_H
#define LAB9_CELLPHONE_H


#include <string>

class Cellphone {
private:
    std::string cellphoneIDNumber;
    std::string cellphoneNumber;
    
public:
    /*
     * Default constructor for cellphone
     */
    Cellphone();

    /*
     * Constructor for cellphone given the ID and Number
     */
    Cellphone(std::string cellPhoneIDNumber, std::string cellphoneNumber);

    /*
     * Getter for cellphone ID
     */
    const std::string &getCellphoneIdNumber() const;

    /*
     * setter for cellphone ID number
     */
    void setCellphoneIdNumber(const std::string &cellphoneIdNumber);

    /*
     * Getter for cellphone number
     */
    const std::string &getCellphoneNumber() const;

    /*
     * setter for cellphone ID number
     */
    void setCellphoneNumber(const std::string &cellphoneNumber);

    /*
     * Destructor for Cellphone objects
     */
    ~Cellphone();
};


#endif //LAB9_CELLPHONE_H
