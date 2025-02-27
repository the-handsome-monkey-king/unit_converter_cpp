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
#include <iostream>

// Currency symbols
enum class CurrencyUnits {
  CAD, USD, EUR, JPY, GBP,
  AUD, CHF, CNY, SEK, NZD};



class Currency {
  private:
    // currently set currency type
    CurrencyUnits units;
    // store negative as independent value
    bool negative;
    // whole and decimal value
    int value, decimal;
    const static std::map<CurrencyUnits, std::string> currencyName;

/*
  const static std::map<CurrencyUnits, std::string> currencyName = {
    {CurrencyUnits::CAD, "CAD"},
    {CurrencyUnits::USD, "USD"},
    {CurrencyUnits::EUR, "EUR"},
    {CurrencyUnits::JPY, "JPY"},
    {CurrencyUnits::GBP, "GBP"},
    {CurrencyUnits::AUD, "AUD"},
    {CurrencyUnits::CHF, "CHF"},
    {CurrencyUnits::CNY, "CNY"},
    {CurrencyUnits::SEK, "SEK"},
    {CurrencyUnits::NZD, "NZD"}
  };
  */

  public:
    // constructors
    Currency(CurrencyUnits units, double value);

    // extractor
    friend std::ostream& operator<<(std::ostream& os,
      const Currency& c);

    // a stub function
    std::string stub();
};

#endif
   
