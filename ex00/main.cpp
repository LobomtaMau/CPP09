#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return EXIT_FAILURE;
    }

    // DatePriceMap db;
    // loadDatabase("database.csv", db);
    // processTransactions(argv[1], db);

    return EXIT_SUCCESS;
}
