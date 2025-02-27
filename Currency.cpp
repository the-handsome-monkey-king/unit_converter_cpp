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
Currency::Currency(CurrencyUnits units, int value, int subvalue) {
  this->units = units;
  this->value = value;
  this->subvalue = subvalue;

  // if units are JPY, throw exception
  if((units == CurrencyUnits::JPY) && (subvalue != 0)) {
    throw std::invalid_argument("JPY does not have any decimal value");
  }
}
      
Currency::Currency(CurrencyUnits units, int value) {
  this->units = units;
  this->value = value;
  this->subvalue = 0;
}


// a stub class
std::string Currency::stub() {
  return "stub";
}
