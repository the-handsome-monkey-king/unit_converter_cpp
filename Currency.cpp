/***********************************

  Currency.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation file for the Currency class.

**********************************/

#include <string>
#include <stdexcept>
#include "Currency.h"

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
