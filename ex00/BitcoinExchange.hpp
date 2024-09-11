#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

typedef std::map<std::string, float> BtcMap;
void loadExchangeRate(const std::string &filename, BtcMap &database);
void doConvertion(const std::string &filename, const BtcMap &exchangeRates);

#endif