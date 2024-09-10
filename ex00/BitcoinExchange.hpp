#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <limits>


typedef std::map<std::string, float> BtcMap;



void loadData(const std::string &filename, BtcMap &database);
// float findClosestValue(const DataPrice &dbt, const std::string &date);
// void transactions(const std::string &filen, const DataPrice &dtb);

#endif