/************************

  test_currency.cpp

  Testing for Currency class

  @author Ryan Morehouse
  @license GNU3


************************/

#include <string>
#include <iostream>
#include <list>
#include "Currency.h"

int main(int argc, char *argv[]) {
  // test all currency types
  Currency cad = Currency(CurrencyUnits::CAD, 10);
  Currency usd = Currency(CurrencyUnits::USD, 10);
  Currency eur = Currency(CurrencyUnits::EUR, 10);
  Currency jpy = Currency(CurrencyUnits::JPY, 10);
  Currency gbp = Currency(CurrencyUnits::GBP, 10);
  Currency aud = Currency(CurrencyUnits::AUD, 10);
  Currency chf = Currency(CurrencyUnits::CHF, 10);
  Currency cny = Currency(CurrencyUnits::CNY, 10);
  Currency sek = Currency(CurrencyUnits::SEK, 10);
  Currency nzd = Currency(CurrencyUnits::NZD, 10);

  std::list<Currency> money;
  money.push_back(cad);
  money.push_back(usd);
  money.push_back(eur);
  money.push_back(jpy);
  money.push_back(gbp);
  money.push_back(aud);
  money.push_back(chf);
  money.push_back(cny);
  money.push_back(sek);
  money.push_back(nzd);

  for(Currency c : money) {
    std::cout << c << std::endl;
  }

  std::cout << "stub" << std::endl;
  return 0;
}
