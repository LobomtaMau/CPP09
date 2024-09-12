#include "RPN.hpp"

RPN::RPN(const std::string &equation) : equation(equation) {}

bool RPN::isOp(char c) const
{
    return (c == '+' || c == '-' || c == '/' ||c == '*');
}

int RPN::doOp(char op, int a, int b)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                throw RPNException("Error: can't dive by zero!\n");
            }
            return a / b;

        default:
            throw RPNException("Error: invalid operation1!\n");
    }
}

void RPN::checkEquation()
{
    std::stack<int> operador;
    std::stringstream ss(equation);
    std::string tokens;

    try {
        while ( ss >> tokens)
        {
            if (isdigit(tokens[0]))
            {
                int num = std::atoi(tokens.c_str());
                if (num < 0 || num > 9) {
                    throw RPNException("Error: number not between 0 and 9!");
                }
                operador.push(num);
            }

            else if (isOp(tokens[0]) && tokens.size() == 1)
            {
                if (operador.size() < 2 ) {
                    throw RPNException("Error: not enoth numbers!");
                }

                int b = operador.top();
                operador.pop();
                int a = operador.top();
                operador.pop();

                int res = doOp(tokens[0], a, b);
                operador.push(res);
            }

            else {
                throw RPNException("Error: invalid operators!2");
            }
        }

        if (operador.size() != 1) {
            throw RPNException("Error: too many operators!3\n");
        }

        std::cout << "Result: " << operador.top() << "\n";

    }

    catch (const RPNException &e) {
        std::cerr << e.what() << "\n";
    }

}
