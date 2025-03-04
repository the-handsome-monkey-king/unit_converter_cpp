/************************

  test_currency.cpp

  Testing for Currency class

  @author Ryan Morehouse
  @license GNU3


************************/

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Currency.h"

// a quick, messy test framework
// for string outputs
class Test {
  public:
    std::vector<std::string> cases;
    std::vector<std::string> results;
    std::vector<int> errors;
    std::string name;

    Test(std::vector<std::string> c, std::string n) { 
      this->cases = c;
      this->name = n;
    }

    void add_result(std::string s) {
      results.push_back(s);
    }

    void run() {
      std::cout << "--- Testing: " << this->name << std::endl;
      std::cout << "Result: ";

      errors.clear();
      
      // right # of results
      if(cases.size() != results.size()) {
        std::cout << "Fail" << std::endl;
        std::cout << "Number of results (" << results.size() << ")";
        std::cout << "does not match number of cases(";
        std::cout << cases.size() << ")" << std::endl;

        return;
      }

      // test all cases, store errors as indexes
      for(unsigned int i = 0; i < cases.size(); i++) {
        if( 0 != cases[i].compare(results[i])) {
          errors.push_back(i);
        }
      }

      // check for errors
      if(errors.empty()) {
        std::cout << "Passed" << std::endl;
      } else {
        std::cout << "Failed" << std::endl;
        std::vector<int>::iterator it;
        for(it = errors.begin(); it != errors.end(); it++) {
          std::cout << "Test Case " << *it << std::endl;
          std::cout << "Expected: " << cases[*it] << std::endl;
          std::cout << "Resulted: " << results[*it] << std::endl;
        }
      }
    }
};

int main(int argc, char *argv[]) {

  // some sample Currency instances
  Currency cad = Currency(CurrencyUnits::CAD, 10.50);
  Currency usd = Currency(CurrencyUnits::USD, 11.50);
  Currency eur = Currency(CurrencyUnits::EUR, 12.50);
  Currency jpy = Currency(CurrencyUnits::JPY, 13.50);
  Currency gbp = Currency(CurrencyUnits::GBP, 14.50);
  Currency aud = Currency(CurrencyUnits::AUD, 15.50);
  Currency chf = Currency(CurrencyUnits::CHF, 16.50);
  Currency cny = Currency(CurrencyUnits::CNY, 17.50);
  Currency sek = Currency(CurrencyUnits::SEK, 18.50);
  Currency nzd = Currency(CurrencyUnits::NZD, 19.50);

  // a vector to hold the Currency samples
  std::vector<Currency> money;
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

  // a vector to hold all the CurrencyUnit values
  std::vector<CurrencyUnits> currencyUnits = {
    CurrencyUnits::CAD, CurrencyUnits::USD, CurrencyUnits::EUR, 
    CurrencyUnits::JPY, CurrencyUnits::GBP, CurrencyUnits::AUD, 
    CurrencyUnits::CHF, CurrencyUnits::CNY, CurrencyUnits::SEK, 
    CurrencyUnits::NZD};

  // test cases 
  std::vector<std::string> cases = {
    "CAD 10.50", "USD 11.50", "EUR 12.50", "JPY 13", "GBP 14.50",
    "AUD 15.50", "CHF 16.50", "CNY 17.50", "SEK 18.50", "NZD 19.50"};

  // test the get string function
  Test test_str(cases, "getString()");

  // get outputs of getString()
  for(Currency c : money) {
    test_str.add_result(c.getString());
  }

  test_str.run();

  // whitespace
  std::cout << std::endl << std::endl;

  // test exchange rate getters
  cases.clear();
   
  // CAD to X
  cases.push_back("1.0000");
  cases.push_back("0.7600");
  cases.push_back("0.6800");
  cases.push_back("82.4300");
  cases.push_back("0.6100");
  cases.push_back("1.0900");
  cases.push_back("0.7500");
  cases.push_back("5.2600");
  cases.push_back("7.1200");
  cases.push_back("1.1400");
  // USD to X
  cases.push_back("1.3100");
  cases.push_back("1.0000");
  cases.push_back("0.8900");
  cases.push_back("107.7400");
  cases.push_back("0.7900");
  cases.push_back("1.4200");
  cases.push_back("0.9800");
  cases.push_back("6.8800");
  cases.push_back("9.3100");
  cases.push_back("1.4900");
  // EUR to X
  cases.push_back("1.4800");
  cases.push_back("1.1300");
  cases.push_back("1.0000");
  cases.push_back("121.6000");
  cases.push_back("0.9000");
  cases.push_back("1.6000");
  cases.push_back("1.1100");
  cases.push_back("7.7600");
  cases.push_back("10.5100");
  cases.push_back("1.6800");
  // JPY to X
  cases.push_back("0.0120");
  cases.push_back("0.0093");
  cases.push_back("0.0082");
  cases.push_back("1.0000");
  cases.push_back("0.0074");
  cases.push_back("0.0130");
  cases.push_back("0.0091");
  cases.push_back("0.0640");
  cases.push_back("0.0860");
  cases.push_back("0.0140");
  // GBP to X
  cases.push_back("1.6400");
  cases.push_back("1.2600");
  cases.push_back("1.1100");
  cases.push_back("135.4600");
  cases.push_back("1.0000");
  cases.push_back("1.7900");
  cases.push_back("1.2400");
  cases.push_back("8.6500");
  cases.push_back("11.7000");
  cases.push_back("1.8700");
  // AUD to X
  cases.push_back("0.9200");
  cases.push_back("0.7000");
  cases.push_back("0.6200");
  cases.push_back("75.8100");
  cases.push_back("0.5600");
  cases.push_back("1.0000");
  cases.push_back("0.6900");
  cases.push_back("4.8400");
  cases.push_back("6.5500");
  cases.push_back("1.0500");
  // CHF to X
  cases.push_back("1.3300");
  cases.push_back("1.0100");
  cases.push_back("0.9000");
  cases.push_back("109.3000");
  cases.push_back("0.8100");
  cases.push_back("1.4400");
  cases.push_back("1.0000");
  cases.push_back("6.9800");
  cases.push_back("9.4400");
  cases.push_back("1.5100");
  // CNY to X
  cases.push_back("0.1900");
  cases.push_back("0.1500");
  cases.push_back("0.1300");
  cases.push_back("15.6600");
  cases.push_back("0.1200");
  cases.push_back("0.2100");
  cases.push_back("0.1400");
  cases.push_back("1.0000");
  cases.push_back("1.3500");
  cases.push_back("0.2200");
  // SEK to X
  cases.push_back("0.1400");
  cases.push_back("0.1100");
  cases.push_back("0.0950");
  cases.push_back("11.5700");
  cases.push_back("0.0850");
  cases.push_back("0.1500");
  cases.push_back("0.1100");
  cases.push_back("0.7400");
  cases.push_back("1.0000");
  cases.push_back("0.1600");
  // NZD to X
  cases.push_back("0.8800");
  cases.push_back("0.6700");
  cases.push_back("0.5900");
  cases.push_back("72.3300");
  cases.push_back("0.5300");
  cases.push_back("0.9500");
  cases.push_back("0.6600");
  cases.push_back("4.6200");
  cases.push_back("4.6200");
  cases.push_back("1.0000");


  // get test class for exchange rates
  Test test_rates(cases, "getExchangeRate()");

  // load results into test class
  for(Currency account : money) {
    // for each account
    // for each existing type of currency
    for(CurrencyUnits cu : currencyUnits) {
      // get individual exchange rate
      double d = account.getExchangeRate(account.getCurrencyUnits(), cu);

      // convert rate into string
      std::stringstream ss;
      ss << std::fixed << std::setprecision(4) << d;

      // add resulting string to cases
      test_rates.add_result(ss.str());
      /*
      std::cout << account << std::endl;
      std::cout << "Exchange rate to " << account.currencyName.at(cu);
      std::cout << ": " << ss.str() << std::endl;
      */
    }
  }

  // run test
  test_rates.run();

  // whitespace
  std::cout << std::endl << std::endl;
  return 0;
}
