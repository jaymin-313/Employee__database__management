#ifndef validate_flag
#define validate_flag

#include<regex>

//bool validateAlphabetic(const std::string& str) {
//    std::regex pattern("^[A-Za-z]+$");
//    return std::regex_match(str, pattern);
//}
bool validateAlphaNumeric(const std::string& str);
bool validateAlphabetic(const std::string& str);

bool validateNumeric(const std::string& str);

bool validateEmail(const std::string& email);

bool validatePhoneNumber(const std::string& phoneNumber);

bool validateDateOfBirth(const std::string& dob);



#endif // !validate_flag