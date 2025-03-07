/***********************************

  UnitConverter.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation file for the UnitConverter class.

**********************************/

#include "UnitConverter.h"

UnitConverter::UnitConverter() {}

double UnitConverter::exchangeCurrency(
  CurrencyUnits fromUnits, CurrencyUnits toUnits, double amount) {

    // get exchange rate
    double rate = EXCHANGE.at(fromUnits).at(toUnits);

    // convert amount
    return amount * rate;
}
