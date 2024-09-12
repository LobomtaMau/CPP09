#include "BitcoinExchange.hpp"

void loadExchangeRate(const std::string &filename, BtcMap &database)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not read exchange rate file!\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, exchangeRate;

        std::getline(ss, date, ',');
        std::getline(ss, exchangeRate);

        date.erase(date.find_last_not_of(" \n\t\r") + 1);
        exchangeRate.erase(0, exchangeRate.find_first_not_of(" \n\t\r"));

        char *end;
        float rate = std::strtof(exchangeRate.c_str(), &end);
        if (*end != '\0' || exchangeRate.empty())
        {
            std::cerr << "Error: invalid exchange rate -> " << exchangeRate << "\n";
            continue;
        }
        database[date] = rate;
    }
    file.close();
}

bool ft_sToI(const std::string &str, int &result)
{
    std::stringstream ss(str);
    ss >> result;
    if (ss.fail() || !ss.eof()) {
        return false;
    }
    return true;
}

bool validateDate(const std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int day, month, year;

    if (!ft_sToI(date.substr(0,4), year) ||
        !ft_sToI(date.substr(5,2), month) ||
        !ft_sToI(date.substr(8,2), day)) {
            return false;
        }

    if (month < 1 || month > 12) {
        return false;
    }

    int dayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool bisexto = (year % 100 != 0 && year % 4 == 0) || (year % 400 == 0);
    
    if (month == 2 && bisexto){
        if (day > 29)
            return false;
    }
    else if (day > dayInMonth[month]) {
        return false;
    }

    return true;
}

void doConvertion(const std::string &filename, const BtcMap &exchangeRates)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not read input file!\n";
        exit(EXIT_FAILURE);
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, value;

        std::getline(ss, date, '|');
        std::getline(ss, value);

        date.erase(date.find_last_not_of(" \n\t\r") + 1);
        value.erase(0, value.find_first_not_of(" \n\t\r"));

        if (!validateDate(date))
        {
            std::cerr << "Error: invalid date -> " << date << "\n";
            continue;
        }

        char *end;
        float btcQT = std::strtof(value.c_str(), &end);
        if (btcQT < 0 || btcQT > 1000 || *end != '\0' || value.empty())
        {
            std::cerr << "Error: invalid value -> " << value << "\n";
            continue;
        }

        BtcMap::const_iterator i = exchangeRates.lower_bound(date);

        if (i == exchangeRates.end() || i->first != date) {
            if (i == exchangeRates.begin()) {
                std::cerr << "Error: no earlier date found for -> " << date << "\n";
                continue;
            }
            --i;
        }
        float rate = i->second;
        std::cout << date << " => " << btcQT << " = " << (btcQT * rate) << "\n";
    }
    file.close();
}
