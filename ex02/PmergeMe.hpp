#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <exception>
#include <algorithm>
#include <limits.h>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        void parseIN(int argc, char **argv);
        void sortVec();
        void sortDeq();
        void displayTime();
        
        class PMException : public std::exception
        {
            private:
                const char* _msg;
            public:
                explicit PMException(const char* message) : _msg(message) {}

                virtual const char* what() const throw() {
                    return _msg;
                }
        };

    private:
        std::vector<int> _vec;
        std::deque<int> _deq;
        double _timeVec;
        double _timeDeq;

        void mergeInsertVec(std::vector<int> &vector);
        void mergeInsertDeq(std::deque<int> &deque);

        bool isValid(const std::string &str);

};

#endif