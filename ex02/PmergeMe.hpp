#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

class PmergeMe
{
    public:
        PmergeMe();
        ~PmergeMe();

        bool parsingArgs(int argc, char **argv, std::vector<int> &next);
        void mergeSortVecDeq(std::vector<int> &container);
        void mergeSortVecDeq(std::deque<int> &container);

        template<typename Container>
        void printSequence(const std::string &name, const Container &container);

        double getTimeInMS()const;

    private:
        template<typename Container>
        void merge(Container &container, Container &left, Container & right);

};

#endif