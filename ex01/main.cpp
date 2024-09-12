#include "RPN.hpp"

int main(int argc, char **argv)
{
    if(argc != 2) {
        std::cerr << "Use: ./RPN \"nr nr op ...\"\n";
        return EXIT_FAILURE;
    }
    
    std::string equation = argv[1];

    RPN rpn(equation);

    rpn.checkEquation();
 
    return 0;
}