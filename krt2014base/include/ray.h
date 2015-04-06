#ifndef _RAY_H_
#define _RAY_H_

#include "include/vertex.h"
#include "include/vector.h"

class Ray {
 public:
  Vertex P;
  Vector D;
  Vertex position(double t);
};


#endif
