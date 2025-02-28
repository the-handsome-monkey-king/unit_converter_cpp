/***********************************

  Currency.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation file for the Currency class.

CAD
USD
EUR
JPY
GBP
AUD
CHF
CNY
SEK
NZD
**********************************/

#include <string>
#include <stdexcept>
#include "Currency.h"

// strings of currency names
const std::map<CurrencyUnits, std::string> Currency::currencyName = {
  {CurrencyUnits::CAD, "CAD"},
  {CurrencyUnits::USD, "USD"},
  {CurrencyUnits::EUR, "EUR"},
  {CurrencyUnits::JPY, "JPY"},
  {CurrencyUnits::GBP, "GBP"},
  {CurrencyUnits::AUD, "AUD"},
  {CurrencyUnits::CHF, "CHF"},
  {CurrencyUnits::CNY, "CNY"},
  {CurrencyUnits::SEK, "SEK"},
  {CurrencyUnits::NZD, "NZD"}};
  
// INDIVIDUAL EXCHANGE RATES

// CAD to X
const std::map<CurrencyUnits, double> Currency::CADexchange = {
  {CurrencyUnits::CAD, 1.0}, 
  {CurrencyUnits::USD, 0.76}, 
  {CurrencyUnits::EUR, 0.68}, 
  {CurrencyUnits::JPY, 82.43}, 
  {CurrencyUnits::GBP, 0.61}, 
  {CurrencyUnits::AUD, 1.09}, 
  {CurrencyUnits::CHF, 0.75}, 
  {CurrencyUnits::CNY, 5.26}, 
  {CurrencyUnits::SEK, 7.12}, 
  {CurrencyUnits::NZD, 1.14}}; 
// USD to X
const std::map<CurrencyUnits, double> Currency::USDexchange = {
  {CurrencyUnits::CAD, 1.31}, 
  {CurrencyUnits::USD, 1.0}, 
  {CurrencyUnits::EUR, 0.89}, 
  {CurrencyUnits::JPY, 107.74}, 
  {CurrencyUnits::GBP, 0.79}, 
  {CurrencyUnits::AUD, 1.42}, 
  {CurrencyUnits::CHF, 0.98}, 
  {CurrencyUnits::CNY, 6.88}, 
  {CurrencyUnits::SEK, 9.31}, 
  {CurrencyUnits::NZD, 1.49}}; 
// EUR to X
const std::map<CurrencyUnits, double> Currency::EURexchange = {
  {CurrencyUnits::CAD, 1.48}, 
  {CurrencyUnits::USD, 1.13}, 
  {CurrencyUnits::EUR, 1.0}, 
  {CurrencyUnits::JPY, 121.6}, 
  {CurrencyUnits::GBP, 0.9}, 
  {CurrencyUnits::AUD, 1.6}, 
  {CurrencyUnits::CHF, 1.11}, 
  {CurrencyUnits::CNY, 7.76}, 
  {CurrencyUnits::SEK, 10.51}, 
  {CurrencyUnits::NZD, 1.68}}; 
// JPY to X
const std::map<CurrencyUnits, double> Currency::JPYexchange = {
  {CurrencyUnits::CAD, 0.012}, 
  {CurrencyUnits::USD, 0.0093}, 
  {CurrencyUnits::EUR, 0.0082}, 
  {CurrencyUnits::JPY, 1.0}, 
  {CurrencyUnits::GBP, 0.0074}, 
  {CurrencyUnits::AUD, 0.013}, 
  {CurrencyUnits::CHF, 0.0091}, 
  {CurrencyUnits::CNY, 0.064}, 
  {CurrencyUnits::SEK, 0.086}, 
  {CurrencyUnits::NZD, 0.014}}; 
// GBP to X
const std::map<CurrencyUnits, double> Currency::GBPexchange = {
  {CurrencyUnits::CAD, 1.64}, 
  {CurrencyUnits::USD, 1.26}, 
  {CurrencyUnits::EUR, 1.11}, 
  {CurrencyUnits::JPY, 135.46}, 
  {CurrencyUnits::GBP, 1.0}, 
  {CurrencyUnits::AUD, 1.79}, 
  {CurrencyUnits::CHF, 1.24}, 
  {CurrencyUnits::CNY, 8.65}, 
  {CurrencyUnits::SEK, 11.7}, 
  {CurrencyUnits::NZD, 1.87}}; 
// AUD to X
const std::map<CurrencyUnits, double> Currency::AUDexchange = {
  {CurrencyUnits::CAD, 0.92}, 
  {CurrencyUnits::USD, 0.7}, 
  {CurrencyUnits::EUR, 0.62}, 
  {CurrencyUnits::JPY, 75.81}, 
  {CurrencyUnits::GBP, 0.56}, 
  {CurrencyUnits::AUD, 1.0}, 
  {CurrencyUnits::CHF, 0.69}, 
  {CurrencyUnits::CNY, 4.84}, 
  {CurrencyUnits::SEK, 6.55}, 
  {CurrencyUnits::NZD, 1.05}}; 
// CHF to X
const std::map<CurrencyUnits, double> Currency::CHFexchange = {
  {CurrencyUnits::CAD, 1.33}, 
  {CurrencyUnits::USD, 1.01}, 
  {CurrencyUnits::EUR, 0.9}, 
  {CurrencyUnits::JPY, 109.3}, 
  {CurrencyUnits::GBP, 0.81}, 
  {CurrencyUnits::AUD, 1.44}, 
  {CurrencyUnits::CHF, 1.0}, 
  {CurrencyUnits::CNY, 6.98}, 
  {CurrencyUnits::SEK, 9.44}, 
  {CurrencyUnits::NZD, 1.51}}; 
// CNY to X
const std::map<CurrencyUnits, double> Currency::CNYexchange = {
  {CurrencyUnits::CAD, 0.19}, 
  {CurrencyUnits::USD, 0.15}, 
  {CurrencyUnits::EUR, 0.13}, 
  {CurrencyUnits::JPY, 15.66}, 
  {CurrencyUnits::GBP, 0.12}, 
  {CurrencyUnits::AUD, 0.21}, 
  {CurrencyUnits::CHF, 0.14}, 
  {CurrencyUnits::CNY, 1.0}, 
  {CurrencyUnits::SEK, 1.35}, 
  {CurrencyUnits::NZD, 0.22}}; 
// SEK to X
const std::map<CurrencyUnits, double> Currency::SEKexchange = {
  {CurrencyUnits::CAD, 0.14}, 
  {CurrencyUnits::USD, 0.11}, 
  {CurrencyUnits::EUR, 0.095}, 
  {CurrencyUnits::JPY, 11.57}, 
  {CurrencyUnits::GBP, 0.085}, 
  {CurrencyUnits::AUD, 0.15}, 
  {CurrencyUnits::CHF, 0.11}, 
  {CurrencyUnits::CNY, 0.74}, 
  {CurrencyUnits::SEK, 1.0}, 
  {CurrencyUnits::NZD, 0.16}}; 
// NZD to X
const std::map<CurrencyUnits, double> Currency::NZDexchange = {
  {CurrencyUnits::CAD, 0.88}, 
  {CurrencyUnits::USD, 0.67}, 
  {CurrencyUnits::EUR, 0.59}, 
  {CurrencyUnits::JPY, 72.33}, 
  {CurrencyUnits::GBP, 0.53}, 
  {CurrencyUnits::AUD, 0.95}, 
  {CurrencyUnits::CHF, 0.66}, 
  {CurrencyUnits::CNY, 4.62}, 
  {CurrencyUnits::SEK, 4.62}, 
  {CurrencyUnits::NZD, 1.0}}; 

const std::map<CurrencyUnits,
  const std::map<CurrencyUnits, double>> EXCHANGE = {
    { CurrencyUnits::CAD, Currency::CADexchange},
    { CurrencyUnits::USD, Currency::USDexchange},
    { CurrencyUnits::EUR, Currency::EURexchange},
    { CurrencyUnits::JPY, Currency::JPYexchange},
    { CurrencyUnits::GBP, Currency::GBPexchange},
    { CurrencyUnits::AUD, Currency::AUDexchange},
    { CurrencyUnits::CHF, Currency::CHFexchange},
    { CurrencyUnits::CNY, Currency::CNYexchange},
    { CurrencyUnits::SEK, Currency::SEKexchange},
    { CurrencyUnits::NZD, Currency::NZDexchange}};

// constructor
Currency::Currency(CurrencyUnits units, double value) {
  this->units = units;

  // initialize negative
  this->negative = false;

  // if negative, store and work with positive digits
  if(value < 0) { 
    this->negative = true;
    value *= -1;
  } 

  // truncates any value below two decimal places
  int temp_value = static_cast<int>(value * 100);
  // store whole currency values
  this->value = temp_value / 100;

  // store decinal value to two places
  this->decimal = temp_value % 100;

  // this currency is JPY, drop any decimal
  if(this->units == CurrencyUnits::JPY) {
    this->decimal = 0;
  }
}

std::ostream& operator<<(std::ostream& os,
  const Currency& c) {
    // using find to preserve const c refernce
    std::string cn = Currency::currencyName.find(c.units)->second;
    os << cn << " ";

    // negative if present
    if(c.negative) { os << "-"; }

    // value
    os << c.value;

    // JPY has no decimal
    if (c.units != CurrencyUnits::JPY) {
      os << "." << c.decimal;
      if(c.decimal < 10) { os << "0";}
    }

    return os;
}

CurrencyUnits Currency::getCurrencyUnits() {
  return this->units;
}
