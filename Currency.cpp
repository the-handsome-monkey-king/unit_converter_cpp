/***********************************

  Currency.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation file for the Currency class.

**********************************/

#include <string>
#include <stdexcept>
#include "Currency.h"

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
    if(c.negative) { os << "-"; }

    // add symbols

    os << c.value << "." << c.decimal;
    if(c.decimal < 10) { os << "0";}

    return os;
}

// a stub class
std::string Currency::stub() {
  return "stub";
}
