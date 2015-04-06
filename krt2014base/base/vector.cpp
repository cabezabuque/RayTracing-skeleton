#include <math.h>

#include "include/vector.h"

Vector::Vector()
{
  x = 0.0;
  y = 0.0;
  z = 0.0;
}

void Vector::set(double px, double py, double pz)
{
  x = px;
  y = py;
  z = pz;
}

void Vector::normalise(void)
{
  double l;

  l = x*x+y*y+z*z;
  l = sqrt(l);

  x = x/l;
  y = y/l;
  z = z/l;
}

double Vector::dot(const Vector &b)
{
  return (x*b.x)+(y*b.y)+(z*b.z);
}
