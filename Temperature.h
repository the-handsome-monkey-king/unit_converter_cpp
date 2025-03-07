/************************************************

  Temperature.h

  @author Ryan Morehouse
  @license GNU3

  A header to store temperature units and conversion factors.

*************************************************/

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <vector>

enum class TempUnits {K, C, F};


class Temperature {
  private:
    double K_to_C(double measure);
    double K_to_F(double measure);
    double C_to_K(double measure);
    double C_to_F(double measure);
    double F_to_K(double measure);
    double F_to_C(double measure);
  public:
    static const std::vector<TempUnits> allTempUnits;
    double convert(TempUnits from, TempUnits to, double measure); 
};


#endif 
