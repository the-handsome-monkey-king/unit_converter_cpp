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
enum class CurrencyIndex {
  CAD, USD, EUR, JPY, GBP,
  AUD, CHF, CNY, SEK, NZD};

class Currency {
  private:
    CurrencyIndex type;
  public:
    Currency(CurrencyIndex type, int value, int subvalue) {};
    std::string stub();
};

#endif
   
