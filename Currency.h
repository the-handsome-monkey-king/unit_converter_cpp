/********************
  
  Currency.h

  @author Ryan Morehouse
  @license GNU3

  A class to represent currencies, as well as
  manage exchange between currency types. Note this
  exchange function is lossy, since exchange rates
  produce currency amounts below the two-or-zero
  point precision of these currencies, so each 
  exchange may result in a loss of currency.

  Note also these exchange rates were selected at an
  arbitrary time, so they are not current values.

  Currencies: CAD, USD, EUR, JPY
    GBP, AUD, CHF, CNY, SEK, NZD

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
    // currency as whole units only
    long amt;

  public:
    // currency units as strings
    static const std::map<CurrencyUnits, std::string> currencyName;

    // INDIVIDUAL EXCHANGE RATES

    // CAD to X
    static const std::map<CurrencyUnits, double> CADexchange;
    // USD to X
    static const std::map<CurrencyUnits, double> USDexchange;
    // EUR to X
    static const std::map<CurrencyUnits, double> EURexchange;
    // JPY to X
    static const std::map<CurrencyUnits, double> JPYexchange;
    // GBP to X
    static const std::map<CurrencyUnits, double> GBPexchange;
    // AUD to X
    static const std::map<CurrencyUnits, double> AUDexchange;
    // CHF to X
    static const std::map<CurrencyUnits, double> CHFexchange;
    // CNY to X
    static const std::map<CurrencyUnits, double> CNYexchange;
    // SEK to X
    static const std::map<CurrencyUnits, double> SEKexchange;
    // NZD to X
    static const std::map<CurrencyUnits, double> NZDexchange;

    /* 2D map for fast exchange reference
    *
    *   First map key    = FROM currency
    *   Nested map key   = TO currency
    *   Nested map value = exchange rage
    */
    
    // figuring out how to call is isn't working out well
    static const std::map<CurrencyUnits,
      const std::map<CurrencyUnits, double>> Exchange;

    // constructors
    Currency(CurrencyUnits units, double value);


    // GETTERS
    CurrencyUnits getCurrencyUnits();
    double getAmountAsDouble();
    std::string getString();

    // extractor
    friend std::ostream& operator<<(std::ostream& os,
      const Currency& c);

    // try a map
    double getExchangeRate(
      CurrencyUnits from, CurrencyUnits to);
};

#endif
   
