#ifndef _MATERIAL_H_
#define _MATERIAL_H_

#include "include/colour.h"

class Material {
 public:
  Colour ka;
  Colour kd;
  Colour ks;
  Colour kr;
  Colour kt;
  double n;
};

#endif
