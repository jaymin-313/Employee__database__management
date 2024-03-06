#ifndef validate_flag
#define validate_flag

#include<regex>
bool validateEmail(const std::string& email) {

    std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}

bool validatePhoneNumber(const std::string& phoneNumber) {

    std::regex pattern("\\d{10}");
    return std::regex_match(phoneNumber, pattern);
}

bool validateDateOfBirth(const std::string& dob) {

    std::regex pattern("^(0[1-9]|[1-2][0-9]|3[0-1])-(0[1-9]|1[0-2])-(\\d{4})$");

    if (!std::regex_match(dob, pattern)) {
        return false;
    }

    int day = std::stoi(dob.substr(0, 2));
    int month = std::stoi(dob.substr(3, 2));
    int year = std::stoi(dob.substr(6, 4));

    if (year < 1900 || year > 9999) {
        return false;
    }
    if (month < 1 || month > 12) {
        return false;
    }
    if (day < 1 || day > 31) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return false;
            }
        }
        else {
            if (day > 28) {
                return false;
            }
        }
    }

    return true;
}

#endif // !validate_flag
