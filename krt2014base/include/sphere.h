#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "include/object.h"

class Sphere: public Object {
  Vertex sp;
  float  r;
 public:
  Sphere(Vertex &psp, float pr);
  bool intersect(Ray &ray, Hit *h);
};

#endif
