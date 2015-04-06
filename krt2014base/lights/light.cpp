// base class for lights

#include <math.h>

#include "include/light.h"

Light::Light(void)
{
}

void Light::link(Light *light)
{
  lt_next = light;
}

Light *Light::next(void)
{
  return lt_next;
}

void Light::getLightProperties(Vertex &pos, Vector *ldir, Colour *intensity)
{
}
