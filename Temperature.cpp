/************************************************

  Temperature.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation of Temperature.h

  Conversion rates (from Wikipedia)
  K = C + 273.15
  K = (F + 459.67) * (5/9)
  C = K - 273.15
  C = (F - 32) * (5/9)
  F = K * (9/5) - 459.67
  F = C * (9/5) + 32

*************************************************/

#include "Temperature.h"

double Temperature::K_to_C(double measure) {
  return measure - 273.15f;
}

double Temperature::K_to_F(double measure) {
  return (measure * 9.0f / 5.0f) - 459.67f;
}

double Temperature::C_to_K(double measure) {
  return measure + 273.15f;
}

double Temperature::C_to_F(double measure) {
  return (measure * 9.0f / 5.0f) + 32.0f;
}

double Temperature::F_to_K(double measure) {
  return (measure + 459.67f) * 5.0f / 9.0f;
}

double Temperature::F_to_C(double measure) {
  return (measure - 32.0f) * 5.0f / 9.0f;
}

double Temperature::convert(TempUnits from, TempUnits to, double measure) {
  switch(from) {
    // K to ...
    case TempUnits::K:
      switch(to) {
        case TempUnits::K:
          return measure;
          break;
        case TempUnits::C:
          return this->K_to_C(measure);
          break;
        case TempUnits::F:
          return this->K_to_F(measure);
          break;
      }

    // C to ...
    case TempUnits::C:
      switch(to) {
        case TempUnits::K:
          return this->C_to_K(measure);
          break;
        case TempUnits::C:
          return measure;
          break;
        case TempUnits::F:
          return this->C_to_F(measure);
          break;
      }


    // F to ...
    case TempUnits::F:
      switch(to) {
        case TempUnits::K:
          return this->F_to_K(measure);
          break;
        case TempUnits::C:
          return this->F_to_C(measure);
          break;
        case TempUnits::F:
          return measure;
          break;
      }
  }

  return 0.0f;
}


const std::vector<TempUnits> Temperature::allTempUnits = {
  TempUnits::F, 
  TempUnits::C, 
  TempUnits::F};
