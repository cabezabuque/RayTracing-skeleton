// a simple directional light source

#include <math.h>

#include "include/directional_light.h"

// specified by a direction and a colour

DirectionalLight::DirectionalLight(Vector &d, Colour &i)
{
  direction.x = -d.x;
  direction.y = -d.y;
  direction.z = -d.z;
  direction.normalise();
  intensity.set(i.getRed(),i.getGreen(),i.getBlue(),i.getAlpha());
}

// provide the intensity and direction from which light arrives at given vertex

void DirectionalLight::getLightProperties(Vertex &pos, Vector *ldir, Colour *i)
{
  // the direction is always the same (light is infinitely far away)
  ldir->x = direction.x;
  ldir->y = direction.y;
  ldir->z = direction.z;

  // the intensity is always the same (not dependent on where it's going
  i->set(intensity.getRed(),intensity.getGreen(),intensity.getBlue(),intensity.getAlpha());
}
