#ifndef LAB9_CELLPHONE_H
#define LAB9_CELLPHONE_H


#include <string>

class Cellphone {
private:
    std::string cellphoneIDNumber;
    std::string cellphoneNumber;
    
public:
    Cellphone();

    Cellphone(std::string cellPhoneIDNumber, std::string cellphoneNumber);
    
    const std::string &getCellphoneIdNumber() const;
    
    void setCellphoneIdNumber(const std::string &cellphoneIdNumber);
    
    const std::string &getCellphoneNumber() const;
    
    void setCellphoneNumber(const std::string &cellphoneNumber);
    
};


#endif //LAB9_CELLPHONE_H
