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
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// USD to X
static const std::map<CurrencyUnits, double> USDexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 1.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// EUR to X
static const std::map<CurrencyUnits, double> EURexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 1.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// JPY to X
static const std::map<CurrencyUnits, double> JPYexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 1.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// GBP to X
static const std::map<CurrencyUnits, double> GBPexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 1.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// AUD to X
static const std::map<CurrencyUnits, double> AUDexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 1.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// CHF to X
static const std::map<CurrencyUnits, double> CHFexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 1.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// CNY to X
static const std::map<CurrencyUnits, double> CNYexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 1.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// SEK to X
static const std::map<CurrencyUnits, double> SEKexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 1.0}, 
  {CurrencyUnits::NZD, 0.0}}; 
// NZD to X
static const std::map<CurrencyUnits, double> NZDexchange = {
  {CurrencyUnits::CAD, 0.0}, 
  {CurrencyUnits::USD, 0.0}, 
  {CurrencyUnits::EUR, 0.0}, 
  {CurrencyUnits::JPY, 0.0}, 
  {CurrencyUnits::GBP, 0.0}, 
  {CurrencyUnits::AUD, 0.0}, 
  {CurrencyUnits::CHF, 0.0}, 
  {CurrencyUnits::CNY, 0.0}, 
  {CurrencyUnits::SEK, 0.0}, 
  {CurrencyUnits::NZD, 1.0}}; 

    

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
