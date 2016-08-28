#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <unordered_map>


bool _is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}


bool _is_operand(char c)
{
    return c >= '0' && c <= '9' || c >= 'a' && c <= 'z';
}


int _get_priority(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return -1;
    }
}


bool _is_lower_or_equal_priority(char first, char second)
{
    return _get_priority(first) <= _get_priority(second);
}


double _evaluate_expr(double first, char op, double second)
{
    switch (op)
    {
        case '+': return first + second;
        case '-': return first - second;
        case '*': return first * second;
        case '/': return first / second;
    }
    return 0;
}


std::string infix_to_postfix(std::string infix)
{
    std::stack<char> operators;
    std::string postfix = "";

    for (std::size_t i = 0; i < infix.length(); ++i)
    {
        char sign = infix[i];

        if (_is_operator(sign))
        {
            while (!operators.empty() && _is_lower_or_equal_priority(sign, operators.top()))
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(sign);
        }
        else if (_is_operand(sign))
        {
            postfix += sign;
        }
        else if (sign == '(')
        {
            operators.push(sign);
        }
        else if (sign == ')')
        {
            while (operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}


double evaluate_postfix(std::string postfix)
{
    std::stack<char> operands;
    std::unordered_map<char, double> params;
    char result_key;

    std::cout << "Enter a:" << std::endl;
    std::cin >> params['a'];

    std::cout << "Enter b:" << std::endl;
    std::cin >> params['b'];

    std::cout << "Enter c:" << std::endl;
    std::cin >> params['c'];

    std::cout << "Enter d:" << std::endl;
    std::cin >> params['d'];

    std::cout << "Enter e:" << std::endl;
    std::cin >> params['e'];

    for (std::size_t i = 0; i < postfix.length(); ++i)
    {
        char sign = postfix[i];

        if (_is_operand(sign))
        {
            operands.push(sign);
        }
        else if (_is_operator(sign))
        {
            result_key = operands.top(); operands.pop();
            double first = params[result_key];
            double second = params[operands.top()]; operands.pop();

            params[result_key] = _evaluate_expr(second, sign, first);
            operands.push(result_key);
        }
    }

    return params[result_key];
}
