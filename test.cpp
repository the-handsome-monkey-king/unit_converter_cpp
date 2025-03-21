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
  Volume vol;

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
      double c_result = uc.convertCurrency(fromUnits, toUnits, amount);
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
  // Temperature class results
  std::vector<double> tclass_f_from_c;
  std::vector<double> tclass_k_from_c;
  std::vector<double> tclass_c_from_k;
  std::vector<double> tclass_f_from_k;
  std::vector<double> tclass_k_from_f;
  std::vector<double> tclass_c_from_f;
  // UnitConverter class results
  std::vector<double> ucclass_f_from_c;
  std::vector<double> ucclass_k_from_c;
  std::vector<double> ucclass_c_from_k;
  std::vector<double> ucclass_f_from_k;
  std::vector<double> ucclass_k_from_f;
  std::vector<double> ucclass_c_from_f;

  /*
    for a math check - an option could be added to this to run in verbose mode
  std::cout << "Includng visual check in math check against floating-point precisions:";
  std::cout << std::endl;
  std::cout << "[input] -> [wiki] [actual]" << std::endl;
  */

  // get results
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

    // store Temperature class results
    tclass_f_from_c.push_back(temp.convert(TempUnits::C, TempUnits::F, c));
    tclass_k_from_c.push_back(temp.convert(TempUnits::C, TempUnits::K, c));
    tclass_c_from_k.push_back(temp.convert(TempUnits::K, TempUnits::C, k));
    tclass_f_from_k.push_back(temp.convert(TempUnits::K, TempUnits::F, k));
    tclass_k_from_f.push_back(temp.convert(TempUnits::F, TempUnits::K, f));
    tclass_c_from_f.push_back(temp.convert(TempUnits::F, TempUnits::C, f));

    // store UnitConverter class results 
    ucclass_f_from_c.push_back(uc.convertTemp(TempUnits::C, TempUnits::F, c));
    ucclass_k_from_c.push_back(uc.convertTemp(TempUnits::C, TempUnits::K, c));
    ucclass_c_from_k.push_back(uc.convertTemp(TempUnits::K, TempUnits::C, k));
    ucclass_f_from_k.push_back(uc.convertTemp(TempUnits::K, TempUnits::F, k));
    ucclass_k_from_f.push_back(uc.convertTemp(TempUnits::F, TempUnits::K, f));
    ucclass_c_from_f.push_back(uc.convertTemp(TempUnits::F, TempUnits::C, f));
  }

  // compare results
  bool tempPass = false;
  bool ucPass = false;
  
  // test Temperature class results
  if(f_from_c == tclass_f_from_c && k_from_c == tclass_k_from_c &&
    c_from_f == tclass_c_from_f && k_from_f == tclass_k_from_f &&
    c_from_k == tclass_c_from_k && f_from_k == tclass_f_from_k)
  {
    tempPass = true;
  } 

  if(tempPass) {
    std::cout << "Temperature class: Passed" << std::endl;
  } else {
    std::cout << "Temperature class: Failed" << std::endl;
    if(f_from_c != tclass_f_from_c) {
      std::cout << "Failed: C to F" << std::endl;
    }
    if(k_from_c != tclass_k_from_c) {
      std::cout << "Failed: C to K" << std::endl;
    }
    if(c_from_f != tclass_c_from_f) {
      std::cout << "Failed: F to C" << std::endl;
    }
    if(k_from_f != tclass_k_from_f) {
      std::cout << "Failed: F to K" << std::endl;
    }
    if(c_from_k != tclass_c_from_k) {
      std::cout << "Failed: K to C" << std::endl;
    }
    if(f_from_k != tclass_f_from_k) {
      std::cout << "Failed: K to F" << std::endl;
    }
  }

  if(f_from_c == ucclass_f_from_c && k_from_c == tclass_k_from_c &&
    c_from_f == ucclass_c_from_f && k_from_f == tclass_k_from_f &&
    c_from_k == ucclass_c_from_k && f_from_k == tclass_f_from_k)
  {
    ucPass = true;
  } 

  if(ucPass) {
    std::cout << "UnitConverter class: Passed" << std::endl;
  } else {
    std::cout << "UnitConverter class: Failed" << std::endl;
    if(f_from_c != ucclass_f_from_c) {
      std::cout << "Failed: C to F" << std::endl;
    }
    if(k_from_c != ucclass_k_from_c) {
      std::cout << "Failed: C to K" << std::endl;
    }
    if(c_from_f != ucclass_c_from_f) {
      std::cout << "Failed: F to C" << std::endl;
    }
    if(k_from_f != ucclass_k_from_f) {
      std::cout << "Failed: F to K" << std::endl;
    }
    if(c_from_k != ucclass_c_from_k) {
      std::cout << "Failed: K to C" << std::endl;
    }
    if(f_from_k != ucclass_f_from_k) {
      std::cout << "Failed: K to F" << std::endl;
    }
  }

  // TEST VOLUME

  std::cout << "--- Testing Volume ---" << std::endl;

  // system memebership tests

  // get class results
  std::vector<bool> is_si;
  std::vector<bool> is_imp;
  std::vector<bool> is_us;
  for(unsigned int i = 0; i < Volume::ALL_UNITS.size(); i++) {
    VolUnits unit = Volume::ALL_UNITS[i];
    is_si.push_back(vol.is_unit_si(unit));
    is_imp.push_back(vol.is_unit_imp(unit));
    is_us.push_back(vol.is_unit_us(unit));
  }

  // test against test cases
  bool pass_membership_test = true;
  for(unsigned int i = 0; i < Volume::ALL_UNITS.size(); i++) {
    if(i < 7) {
      if(is_si[i] != true || is_imp[i] != false || is_us[i] != false) {
        pass_membership_test = false;
      }
    } else if ( i < 11) {
      if(is_si[i] != false || is_imp[i] != true || is_us[i] != false) {
        pass_membership_test = false;
      }
    } else {
      if(is_si[i] != false || is_imp[i] != false || is_us[i] != true) {
        pass_membership_test = false;
      }
    }
  }

  std::cout << "System Membership Tests: ";
  if(pass_membership_test) {
    std::cout << "Passed" << std::endl;
  } else {
    std::cout << "Failed" << std::endl;
  }




  // TEST MASS



  return 0;
}
