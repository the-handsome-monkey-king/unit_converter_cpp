/********************
  
  UnitConverter.h

  @author Ryan Morehouse
  @license GNU3

  A simple unit converter for:
    currency
    temperature
    volume
    mass

  Currencies: CAD, USD, EUR, JPY
    GBP, AUD, CHF, CNY, SEK, NZD


*********************/

#ifndef UNITCONVERTER_H
#define UNITCONVERTER_H

#include "CurrencyExchangeRates.h"
#include "Temperature.h"
#include "Volume.h"
#include "Mass.h"

class UnitConverter {
  private:
  public:
    UnitConverter();

    // currency
   double convertCurrency(
      CurrencyUnits fromUnits,
      CurrencyUnits toUnits,
      double amount);

  // temperature
  double convertTemp(
    TempUnits fromUnits,
    TempUnits toUnits,
    double measure);

  // volume
  double convertVolume(
    VolUnits fromUnits,
    VolUnits toUnits,
    double measure);

  // mass
  double convertMass(
    MassUnits fromUnits,
    VolUnits toUnits,
    double measure);

};

#endif
   
