#ifndef _LIGHT_H_
#define _LIGHT_H_

#include "include/vertex.h"
#include "include/vector.h"
#include "include/colour.h"

class Light {
  Light *lt_next;
 public:
  Light(void);
  void link(Light *light);
  Light *next(void);
  virtual void getLightProperties(Vertex &pos, Vector *ldir, Colour *i);
};

#endif
