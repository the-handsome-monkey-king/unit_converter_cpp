
/************************************************

  Volume.cpp

  @author Ryan Morehouse
  @license GNU3
  Implementation of Volume.h

*************************************************/

#include "Volume.h"

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
