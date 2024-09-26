#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>
#include <exception>
#include <list>


class RPN
{
    public:
        RPN(const std::string &equation);
        void checkEquation();
    
        class RPNException : public std::exception
        {
            private:
                const char* _msg;
            public:
                explicit RPNException(const char* message) : _msg(message) {}

                virtual const char* what() const throw() {
                    return _msg;
                }
        };

    private:
        std::string equation;

        bool isOp(char c) const;
        int doOp(char op, int a, int b);

        std::list<int> operador;

};

#endif