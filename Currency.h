/********************
  
  Currency.h

  @author Ryan Morehouse
  @license GNU3

  A simple wrapper class  to store a 2-point
  currency value, and to manage conversions between
  different currencies.

  Currencies:
    CAD
    USD
    EUR
    JPY (note zero decimal places)
    GBP
    AUD
    CHF
    CNY
    SEK
    NZD

*********************/

#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <map>

// Currency symbols
enum class CurrencyUnits {
  CAD, USD, EUR, JPY, GBP,
  AUD, CHF, CNY, SEK, NZD};

class Currency {
  private:
    // currently set currency type
    CurrencyUnits units;
    // whole and decimal value
    int value, subvalue;
  public:
    // any currency but JPY cannot have decimal
    Currency(CurrencyUnits units, int value, int subvalue);
    // any currency, sets subvalue to zero
    Currency(CurrencyUnits units, int value);
    std::string stub();
};

#endif
   
