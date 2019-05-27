#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

class operation
{
private:
public:
    std::vector<unsigned short int> plus(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2, std::vector<unsigned short int> &answ);
    std::vector<unsigned short int> minus(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2, std::vector<unsigned short int> &answ);
    std::vector<unsigned short int> multiplication(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2, std::vector<unsigned short int> &answ);
    std::vector<unsigned short int> division(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2, std::vector<unsigned short int> &answ);
    std::vector<unsigned short int> power(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2, std::vector<unsigned short int> &answ);
    bool more(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2);
    bool less(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2);
    bool equally(const std::vector<unsigned short int> &num1, const std::vector<unsigned short int> &num2);

    operation(/* args */);
    ~operation();
};