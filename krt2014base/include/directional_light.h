#ifndef _DIRECTIONAL_LIGHT_H_
#define _DIRECTIONAL_LIGHT_H_

#include "include/light.h"

class DirectionalLight: public Light {
  Vector direction;
  Colour intensity;
 public:
  DirectionalLight(Vector &d, Colour &c);
  virtual void getLightProperties(Vertex &pos, Vector *ldir, Colour *i);
};

#endif
