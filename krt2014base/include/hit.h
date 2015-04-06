#ifndef _HIT_H_
#define _HIT_H_

#include "include/vertex.h"
#include "include/vector.h"

class Object;

class Hit {
 public:
  Vertex p;
  Vector n;
  double t;
  Object *obj;
  Hit(void);
};

#endif
