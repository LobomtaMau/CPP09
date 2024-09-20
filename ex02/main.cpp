#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    try {
        PmergeMe test;
        test.parseIN(argc, argv);

        std::cout << "Before: ";
        for (int i = 1; i < argc; ++i) {
            std::cout << argv[i] << " ";
        }
        std::cout << "\n";

        test.sortVec();
        test.sortDeq();

        test.displayTime();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

