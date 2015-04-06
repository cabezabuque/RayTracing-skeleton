// Object - The base class for objects.

#include <math.h>

#include "include/object.h"

Object::Object(void)
{
}

void Object::link(Object *obj)
{
  obj_next = obj;
}

Object *Object::next(void)
{
  return obj_next;
}

void Object::setMaterial(Material *m)
{
  obj_mat = m;
}


Colour Object::getColour()
{
  Colour a;
  return a;
}

bool Object::sintersect(Ray &ray, Hit *h, double tl)
{
  bool res;
  Hit nh;

  if (this->intersect(ray, &nh) == true)
  {
    if (nh.t > tl) return false;

    *h = nh;

    return true;
  }

  return false;
}
