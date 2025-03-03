/************************

  test_currency.cpp

  Testing for Currency class

  @author Ryan Morehouse
  @license GNU3


************************/

#include <string>
#include <iostream>
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
    
  return 0;
}
