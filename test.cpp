/************************

  test.cpp

  A test program for the cpp implementation
  of a simple unit converter.

  @author Ryan Morehouse
  @license GNU3


************************/

#include <vector>
#include <string>
#include <iostream>
#include "UnitConverter.h"

int main(int argc, char *argv[]) {
  UnitConverter uc;
  CurrencyExchangeRates cer;

  // variables for testing
  double amount = 100.0f;
  std::vector<double> local_results;
  std::vector<double> class_results;

  // TEST CURRENCY EXCHANGE
  std::cout << "--- Testing curency exchange ---" << std::endl;
  
  // convert all currencies to all currencies
  for(unsigned int i = 0; i < cer.ALL_UNITS.size(); i++) {
    for(unsigned int j = 0; j < cer.ALL_UNITS.size(); j++) {
      // get units
      CurrencyUnits fromUnits = cer.ALL_UNITS[i];
      CurrencyUnits toUnits = cer.ALL_UNITS[j];

      // class results
      double c_result = uc.exchangeCurrency(fromUnits, toUnits, amount);
      class_results.push_back(c_result);

      // local results
      double rate = cer.EXCHANGE_RATES.at(fromUnits).at(toUnits);
      double l_result = amount * rate;
      local_results.push_back(l_result);
    }
  }

  // compare results
  if(local_results == class_results) {
    std::cout << "Passed" << std::endl;
  } else {
    std::cout << "Failed" << std::endl;
    for(unsigned int i = 0; i < local_results.size(); i++) {
      std::cout << "Test Case " << i << std::endl;
      std::cout << "Expected: " << local_results[i] << std::endl;
      std::cout << "Result: " << class_results[i] <<std::endl;
    }
  }

  // cleanup currency exchange
  local_results.clear();
  class_results.clear();

  // TEST TEMPERATURE
  // TEST VOLUME
  // TEST MASS



  return 0;
}
