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
  Temperature temp;

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
  std::cout << "--- Testing Temperature ---" << std::endl;

  // quick test cases from wikipedia
  // 0C = 32F = 273.15K
  // 500C = 932F = 773.15K
  // 490C = 914F = 763.15K
  // 10C = 50F = 283.15K
  // -17.78C = 0F = 255.37K
  // -100C = -148F = 173.15K

  // simple wikipedia inputs
  std::vector<double> c_temps = {0.0f, 500.0f, 490.0f, 10.0f, -17.78f, -100.0f};
  std::vector<double> f_temps = {32.0f, 932.0f, 914.0f, 50.0f, 0.0f, -148.0f};
  std::vector<double> k_temps = {273.15f, 773.15f, 763.15f, 283.15f, 255.37f, 173.15f};
  // local results
  std::vector<double> f_from_c;
  std::vector<double> k_from_c;
  std::vector<double> c_from_f;
  std::vector<double> k_from_f;
  std::vector<double> c_from_k;
  std::vector<double> f_from_k;
  // class results
  std::vector<double> class_f_from_c;
  std::vector<double> class_k_from_c;
  std::vector<double> class_c_from_k;
  std::vector<double> class_f_from_k;
  std::vector<double> class_k_from_f;
  std::vector<double> class_c_from_f;

  /*
    for a math check - an option could be added to this to run in verbose mode
  std::cout << "Includng visual check in math check against floating-point precisions:";
  std::cout << std::endl;
  std::cout << "[input] -> [wiki] [actual]" << std::endl;
  */

  for(unsigned int i = 0; i < c_temps.size(); i++) {
    // inputs
    double c = c_temps[i];
    double f = f_temps[i];
    double k = k_temps[i];

    /* 
      local results
      K = C + 273.15
      K = (F + 459.67) * (5/9)
      C = K - 273.15
      C = (F - 32) * (5/9)
      F = K * (9/5) - 459.67
      F = C * (9/5) + 32
    */
    double k_result_from_c = c + 273.15f;
    double k_result_from_f = (f + 459.67f) * 5.0f / 9.0f;
    double c_result_from_k = k - 273.15f;
    double c_result_from_f = (f - 32.0f) * 5.0f / 9.0f;
    double f_result_from_k = (k * 9.0f / 5.0f) - 459.67f;
    double f_result_from_c = (c * 9.0f / 5.0f) + 32.0f;

    /*  MATH CHECK
    std::cout << "K from ..." << std::endl;
    std::cout << c << " C -> " << k << " " << k_result_from_c << std::endl;
    std::cout << f << " F -> " << k << " " << k_result_from_f << std::endl;

    std::cout << "C from ..." << std::endl;
    std::cout << k << " K -> " << c << " " << c_result_from_k << std::endl;
    std::cout << f << " F -> " << c << " " << c_result_from_f << std::endl;

    std::cout << "F from ..." << std::endl;
    std::cout << k << " K -> " << f << " " << f_result_from_k << std::endl;
    std::cout << c << " C -> " << f << " " << f_result_from_c << std::endl;
    std::cout << std::endl;
    */

    // store local results
    k_from_c.push_back(k_result_from_c);
    k_from_f.push_back(k_result_from_f);
    c_from_k.push_back(c_result_from_k);
    c_from_f.push_back(c_result_from_f);
    f_from_k.push_back(f_result_from_k);
    f_from_c.push_back(f_result_from_c);

    // test local results against Temperature class results

    // test local results against UnitConverter class results
  }

  // TEST VOLUME
  // TEST MASS



  return 0;
}
