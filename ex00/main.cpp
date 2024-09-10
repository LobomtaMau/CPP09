#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    (void)argv;
    if (argc != 2) {
        std::cerr << "Use: ./btc input_file\n";
        return EXIT_FAILURE;
    }

    BtcMap database;
    loadData("input.txt", database);
    // processTransactions(argv[1], db);

    return EXIT_SUCCESS;
}
