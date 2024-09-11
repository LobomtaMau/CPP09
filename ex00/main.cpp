#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    (void)argv;
    if (argc != 2) {
        std::cerr << "Use: ./btc input.txt\n";
        return EXIT_FAILURE;
    }

    BtcMap database;
    loadExchangeRate("data.csv", database);
    doConvertion(argv[1], database);

    return EXIT_SUCCESS;
}
