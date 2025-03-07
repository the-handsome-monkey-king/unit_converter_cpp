/********************
  
  CurrencyExchangeRates.h

  @author Ryan Morehouse
  @license GNU3

  A class to manage currency exchange rates.

  Currencies: CAD, USD, EUR, JPY
    GBP, AUD, CHF, CNY, SEK, NZD

*********************/

#ifndef EXCHANGERATES_H
#define EXCHANGERATES_H

#include <map>
#include <vector>
#include <string>

// Currency symbols
enum class CurrencyUnits {
  CAD, USD, EUR, JPY, GBP,
  AUD, CHF, CNY, SEK, NZD};

class CurrencyExchangeRates {
  public:
  // vector for iteration
  static const std::vector<CurrencyUnits> ALL_UNITS;
  // vector for unit names as strings
  static const std::map<CurrencyUnits, std::string> NAMES;

  // Individual exchange rates
  static const std::map<CurrencyUnits,double> FROM_CAD_TO;
  static const std::map<CurrencyUnits,double> FROM_USD_TO;
  static const std::map<CurrencyUnits,double> FROM_EUR_TO;
  static const std::map<CurrencyUnits,double> FROM_JPY_TO;
  static const std::map<CurrencyUnits,double> FROM_GBP_TO;
  static const std::map<CurrencyUnits,double> FROM_AUD_TO;
  static const std::map<CurrencyUnits,double> FROM_CHF_TO;
  static const std::map<CurrencyUnits,double> FROM_CNY_TO;
  static const std::map<CurrencyUnits,double> FROM_SEK_TO;
  static const std::map<CurrencyUnits,double> FROM_NZD_TO;

  // a 2d map of exchange rates FROM units TO new units
  static const std::map<CurrencyUnits,
    const std::map<CurrencyUnits, double>> EXCHANGE_RATES;
};


#endif
