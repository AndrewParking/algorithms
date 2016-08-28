#include <iostream>
#include <string>

#include "postfix.hpp"


int main()
{
    std::string infix;

    std::cout << "Enter infix expression:" << std::endl;
    std::cin >> infix;

    std::string postfix = infix_to_postfix(infix);
    std::cout << postfix << std::endl;

    std::cout << "Result: " << evaluate_postfix(postfix) << std::endl;

    return 0;
}
