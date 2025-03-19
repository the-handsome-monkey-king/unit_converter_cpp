
/************************************************

  Volume.cpp

  @author Ryan Morehouse
  @license GNU3
  Implementation of Volume.h

*************************************************/

#include <cmath>
#include "Volume.h"

// UNITS

const std::map<VolUnits, std::string> Volume::UNIT_NAMES = {
  {VolUnits::SI_KILO_LITRE, "Kilolitres"},
  {VolUnits::SI_HECA_LITRE, "Hecalitres"},
  {VolUnits::SI_DECA_LITRE, "Decalitres"},
  {VolUnits::SI_LITRE, "Litres"},
  {VolUnits::SI_DECI_LITRE, "Decilitres"},
  {VolUnits::SI_CENTI_LITRE, "Centiliters"},
  {VolUnits::SI_MILI_LITRE, "Mililitres"},
  {VolUnits::IMP_OZ, "Imperial Ounces"},
  {VolUnits::IMP_GI, "Imperial Gills"},
  {VolUnits::IMP_PT, "Imperial Pints"},
  {VolUnits::IMP_GAL, "Imperial Gallons"},
  {VolUnits::US_JIG, "US Jig"},
  {VolUnits::US_GI, "US Gill"},
  {VolUnits::US_CUP, "US Cup"},
  {VolUnits::US_PINT, "US Pint"},
  {VolUnits::US_QUART, "US Quart"},
  {VolUnits::US_POTTLE, "US Pottle"},
  {VolUnits::US_GALLON, "US Gallon"}};

// SYSTEM MEMBERSHIPS

const std::unordered_set<VolUnits> Volume::SI_UNITS = {
  VolUnits::SI_KILO_LITRE, 
  VolUnits::SI_HECA_LITRE, 
  VolUnits::SI_DECA_LITRE, 
  VolUnits::SI_LITRE, 
  VolUnits::SI_DECI_LITRE, 
  VolUnits::SI_CENTI_LITRE, 
  VolUnits::SI_MILI_LITRE}; 
  
const std::unordered_set<VolUnits> Volume::IMP_UNITS = {
  VolUnits::IMP_OZ, 
  VolUnits::IMP_GI, 
  VolUnits::IMP_PT, 
  VolUnits::IMP_GAL};

const std::unordered_set<VolUnits> Volume::US_UNITS = {
  VolUnits::US_JIG, 
  VolUnits::US_GI, 
  VolUnits::US_CUP, 
  VolUnits::US_PINT, 
  VolUnits::US_QUART, 
  VolUnits::US_POTTLE, 
  VolUnits::US_GALLON};

// TEST MEMBERSHIPS
const bool Volume::is_unit_si(VolUnits unit) {
  auto it = Volume::SI_UNITS.find(unit);
  if(it != Volume::SI_UNITS.end()) {
    return true;
  }
  return false;
}

const bool Volume::is_unit_imp(VolUnits unit) {
  auto it = Volume::IMP_UNITS.find(unit);
  if(it != Volume::IMP_UNITS.end()) {
    return true;
  }
  return false;
}

const bool Volume::is_unit_us(VolUnits unit) {
  auto it = Volume::US_UNITS.find(unit);
  if(it != Volume::US_UNITS.end()) {
    return true;
  }
  return false;
}


const std::map<VolUnits, double> Volume::SI_EXPONENTS = {
  {VolUnits::SI_KILO_LITRE, 3.0f},
  {VolUnits::SI_HECA_LITRE, 2.0f},
  {VolUnits::SI_DECA_LITRE, 1.0f},
  {VolUnits::SI_LITRE, 0.0f},
  {VolUnits::SI_DECI_LITRE, -1.0f},
  {VolUnits::SI_CENTI_LITRE, -2.0f},
  {VolUnits::SI_MILI_LITRE, -3.0f}};

double Volume::si_to_si(VolUnits from, VolUnits to, double measure) {
  double to_pow = Volume::SI_EXPONENTS.at(to);
  double from_pow = Volume::SI_EXPONENTS.at(from);
  double factor_pow = to_pow - from_pow;
  double new_measure = pow(measure, factor_pow);
  return new_measure;
}

double Volume::convert(VolUnits from, VolUnits to, double measure) {
  //stub
  return 0;
}

// VECTOR FOR ITERATION

const std::vector<VolUnits> Volume::ALL_UNITS = {
  VolUnits::SI_KILO_LITRE, VolUnits::SI_HECA_LITRE, VolUnits::SI_DECA_LITRE,
  VolUnits::SI_LITRE, VolUnits::SI_DECI_LITRE, VolUnits::SI_CENTI_LITRE,
  VolUnits::SI_MILI_LITRE, VolUnits::IMP_OZ, VolUnits::IMP_GI,
  VolUnits::IMP_PT, VolUnits::IMP_GAL, VolUnits::US_JIG,
  VolUnits::US_GI, VolUnits::US_CUP, VolUnits::US_PINT, VolUnits::US_QUART,
  VolUnits::US_POTTLE, VolUnits::US_GALLON};
