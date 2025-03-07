/************************************************

  Temperature.cpp

  @author Ryan Morehouse
  @license GNU3

  Implementation of Temperature.h

*************************************************/

#include "Temperature.h"

double Temperature::K_to_C(double measure) {
  //stub
  return 0.0f;
}

double Temperature::K_to_F(double measure) {
  //stub
  return 0.0f;
}

double Temperature::C_to_K(double measure) {
  //stub
  return 0.0f;
}

double Temperature::C_to_F(double measure) {
  //stub
  return 0.0f;
}

double Temperature::F_to_K(double measure) {
  //stub
  return 0.0f;
}

double Temperature::F_to_C(double measure) {
  //stub
  return 0.0f;
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
