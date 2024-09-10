#include "BitcoinExchange.hpp"

void loadData(const std::string &filename, BtcMap &database) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error could not read file!\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, charValue;

        std::getline(ss, date, '|');
        std::getline(ss, charValue);

        std::cout << "\n"<< date << " =date!!!" 
        << charValue << "=charValue!!!\n";

        date.erase(date.find_last_not_of(" \n\t\r") + 1);
        charValue.erase(0, charValue.find_first_not_of(" \n\t\r"));

        char *end;
        float sToF; // F
        sToF = std::strtof(charValue.c_str(), &end);
        if(sToF < 0 || sToF > 1000 ||*end != '\0' || charValue.empty()){
            std::cerr << "Error: invalid nr!" << charValue << "\n";
            continue;
        }
        database[date] = sToF;
        std::cout << date << " =sToF\n";
        
    }
    file.close();
}
