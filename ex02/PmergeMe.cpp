#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _timeVec(0), _timeDeq(0) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseIN(int argc, char **argv)
{
    for (int i = 1; i < argc; ++i)
    {
        std::string args = argv[i];
        if (!isValid(args)) {
            throw PMException("Error: invalid input!\n");
        }

        long nbr = std::strtol(args.c_str(), NULL, 10);
        if (nbr > INT_MAX || nbr < INT_MIN)
         {
            throw PMException("Error: invalid int!\n");
        }

        _vec.push_back(nbr);
        _deq.push_back(nbr);
    }
}

void PmergeMe::sortVec()
{
    clock_t start = clock();
    mergeInsertVec(_vec);
    clock_t end = clock();
    _timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

void PmergeMe::sortDeq()
{
    clock_t start = clock();
    mergeInsertDeq(_deq);
    clock_t end = clock();
    _timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
}

bool PmergeMe::isValid(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PmergeMe::displayTime()
{
    std::cout << "After Vector sort: ";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << "\n\n";

    std::cout << "After Deque sort: ";
    for (size_t i = 0; i < _deq.size(); i++)
        std::cout << _deq[i] << " ";
    std::cout << "\n\n";

    std::cout << "Time with vector: " << _timeVec<< " msec\n";
    std::cout << "Time with deque: " << _timeDeq << " msec\n";
}

void PmergeMe::mergeInsertVec(std::vector<int> &vector)
{
    if (vector.size() <= 1)
        return;

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < vector.size(); i += 2)
    {
        if (vector[i] > vector[i + 1])
            pairs.push_back(std::make_pair(vector[i + 1], vector[i]));
        else
            pairs.push_back(std::make_pair(vector[i], vector[i + 1]));
    }

    std::vector<int> odd;
    if (vector.size() % 2 != 0)
        odd.push_back(vector.back());

    std::vector<int> sortedVec;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        sortedVec.push_back(pairs[i].first);
    }

    mergeInsertVec(sortedVec);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        int secondElem = pairs[i].second;
        std::vector<int>::iterator it = std::lower_bound(sortedVec.begin(), sortedVec.end(), secondElem);
        sortedVec.insert(it, secondElem);
    }

    if (!odd.empty())
    {
        int oddElem = odd.front();
        std::vector<int>::iterator it = std::lower_bound(sortedVec.begin(), sortedVec.end(), oddElem);
        sortedVec.insert(it, oddElem);
    }

    vector = sortedVec;
}

void PmergeMe::mergeInsertDeq(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < deque.size(); i += 2)
    {
        if (deque[i] > deque[i + 1])
            pairs.push_back(std::make_pair(deque[i + 1], deque[i]));
        else
            pairs.push_back(std::make_pair(deque[i], deque[i + 1]));
    }

    std::deque<int> odd;
    if (deque.size() % 2 != 0)
        odd.push_back(deque.back());

    std::deque<int> sortedDeq;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        sortedDeq.push_back(pairs[i].first);
    }

    mergeInsertDeq(sortedDeq);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        int secondElem = pairs[i].second;
        std::deque<int>::iterator it = std::lower_bound(sortedDeq.begin(), sortedDeq.end(), secondElem);
        sortedDeq.insert(it, secondElem);
    }

    if (!odd.empty())
    {
        int oddElem = odd.front();
        std::deque<int>::iterator it = std::lower_bound(sortedDeq.begin(), sortedDeq.end(), oddElem);
        sortedDeq.insert(it, oddElem);
    }

    deque = sortedDeq;
}


/*std::deque<int> PmergeMe::merge(const std::deque<int> &left, const std::deque<int> &right)
{
    std::deque<int> result;
    std::size_t i = 0, j = 0;

    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            result.push_back(left[i++]);
        else
            result.push_back(right[j++]);
    }

    while (i < left.size())
        result.push_back(left[i++]);

    while (j < right.size())
        result.push_back(right[j++]);

    return result;
}

void PmergeMe::mergeInsertDeq(std::deque<int> &deque)
{
    if (deque.size() <= 1)
        return;

    std::deque<int> left(deque.begin(), deque.begin() + deque.size() / 2);
    std::deque<int> right(deque.begin() + deque.size() / 2, deque.end());

    mergeInsertDeq(left);
    mergeInsertDeq(right);

    deque = merge(left, right);
}*/
