/************************************************

  Volume.h

  @author Ryan Morehouse
  @license GNU3

  A header to store volume units and conversion factors.

  Conversions will convert to base units, then factor up or down.

  -- SI Units --
  base unit: L (litre)
  Prefix Factors:
    k  1000   (kiloLitre)
    h  100    (hecaLitre)
    da 10     (decaLitre)
    d  0.1    (deciLitre)
    c  0.01   (centiLitre)
    m  0.001  (miliLitre)

  -- Imperial Units --
  Base unit: oz (ounce)
  Other Units as oz:
    gi  5   (gill)
    pt  20  (pint)
    qt  40  (quart)
    gal 160 (gallon)

  -- US Customary --
  General Base Unit: cu-in (cubic inch)
  From cu:
    cu-ft   = 1728 cu-in  (cubic foot)
    cu-yd   = 27 cur-ft    (cubic yard)
    acre-ft = 43560 cu-ft (acre-foot)

  Fluid Base Unit: fl-oz (fluid ounce)
  From fl-oz:
    jig 1.5 (shot)
    gi  4   (gill)
    c   8   (cup)
    pt  2c  (pint)
    qt  2pt (quart)
    pot 2qt (pottle)
    gal 4qt (gallon)

  Dry Base Unit: pt (dry pint)
  (1 dry pint = 33.600 3125 cubic inches)
  From dry pt:
    qt  2pt   (dry quart)
    gal 4qt   (dry gallon)
    pk  2gal  (peck)
    bu  4pk   (bushel)

  -- System Conversions --
  1 US fluid ounce = 1.804688 US cubic inches
  1 US fluid ounce = 1.0408 imperial ounce
  1 US fluid ounce = 29.5735295625 mL
  1 US Dry Pint = 33.600 3125 US cubic inches
  1 US Dry Pint = 0.5506104713575 L
  1 imperial ounce = 28.4130625 mL
  1 imperial ounce = 1.7339 US cubic inches
  1 imperial ounce = 0.96076 US ounces 
  1 L = 35.19507973 imperial ounce
  1 L = 33.8140227 US fluid counce


*************************************************/

#ifndef VOLUME_H
#define VOLUME_H

// STUB
enum class VolUnits {LITRE};

#endif 
