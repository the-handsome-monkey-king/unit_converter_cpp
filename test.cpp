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

  // variables for testing
  double amount = 100.0f;
  std::vector<double> local_results;
  std::vector<double> class_results;

  // TEST CURRENCY EXCHANGE
  std::cout << "--- Testing curency exchange ---" << std::endl;
  
  // convert all currencies to all currencies
  for(unsigned int i = 0; i < allCurrencyUnits.size(); i++) {
    for(unsigned int j = 0; j < allCurrencyUnits.size(); j++) {
      // get units
      CurrencyUnits fromUnits = allCurrencyUnits[i];
      CurrencyUnits toUnits = allCurrencyUnits[j];

      // class results
      double cr = uc.exchangeCurrency(fromUnits, toUnits, amount);
      class_results.push_back(cr);

      // local results
      double rate = EXCHANGE.at(fromUnits).at(toUnits);
      double lr = amount * rate;
      local_results.push_back(lr);
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
