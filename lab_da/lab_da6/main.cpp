#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <math.h>

/*
enum operation {
    plus, minus, multiplication, division
}
*/

size_t min_size(const size_t a, const size_t b)
{
    if (a >= b) return b;
    else return a;
}

void plus(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2, std::vector<unsigned short> &answer)
{
    unsigned short help = 0;
    for (size_t i = 0; i < min_size(num1.size(), num2.size()); i++)
    {
        
    }
    
}

void minus(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2, std::vector<unsigned short> &answer)
{

}

void multiplication(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2, std::vector<unsigned short> &answer)
{

}

void division(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2, std::vector<unsigned short> &answer)
{

}

void power(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2, std::vector<unsigned short> &answer)
{

}

bool more(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2)
{

}

bool less(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2)
{

}

bool equal(const std::vector<unsigned short> &num1, const std::vector<unsigned short> &num2)
{

}

void my_atoi(std::string &word, std::vector<unsigned short int> &num)
{
    num.clear();
    num.resize(word.size());
    for (auto i = num.size(); i > 0; --i) {
        num.push_back(word[i] - '0');
    }
    return;
}

void print_answer(std::vector<unsigned short int> &answer)
{
    for (auto i = answer.size(); i > 0; --i) {
        std::cout << answer[i];
    }
    printf("\n");
}

void calcul(std::vector<unsigned short int> &num1, std::vector<unsigned short int> &num2, char operand)
{
    std::vector<unsigned short int> answer;
    switch (operand)
    {
    case '+':
        plus(num1, num2, answer);
        print_answer(answer);
        break;
    case '-':
        minus(num1, num2, answer);
        print_answer(answer);
        break;
    case '*':
        multiplication(num1, num2, answer);
        print_answer(answer);
        break;
    case '/':
        division(num1, num2, answer);
        print_answer(answer);
        break;
    case '^':
        power(num1, num2, answer);
        print_answer(answer);
        break;
    case '>':
        if (more(num1, num2) == true) {
            printf("true\n");
        } else {
            printf("false\n");
        }
        break;
    case '<':
        if (less(num1, num2) == true) {
            printf("true\n");
        } else {
            printf("false\n");
        }
        break;
    case '=':
        if (equal(num1, num2) == true) {
            printf("true\n");
        } else {
            printf("false\n");
        }
        break;
    default:
        break;
    }
}

int main()
{
    bool status = true;
    char symbol;
    std::string word;
    std::vector<unsigned short int> num1;
    std::vector<unsigned short int> num2;
    while (status == true) {
        while (word.size() == 0) {
            std::getline(std::cin, word);
        }
        my_atoi(word, num1);
        word.clear();
        while (word.size() == 0)
        {
            std::getline(std::cin, word);
        }
        my_atoi(word, num2);
        symbol = getchar();
        while (symbol == '\n')
        {
            symbol = getchar();
        }
        if (symbol == EOF) {
            status = false;
        }
    }
    return 0;
}