#include <stdio.h>
#include <stdlib.h>

#include "include/scene.h"
#include "include/sphere.h"
#include "include/directional_light.h"

#define XSIZE 512
#define YSIZE 512

Colour frame_buffer[YSIZE][XSIZE];

float frand()
{
  int x;
  float f;

  x = rand();
  f = (float)(x & 0xffff);
  f = f/65536.0;

  return f;
}

void write_framebuffer()
{
  int x, y;
  float r, g, b;

  printf("P3\n%d %d\n255\n", XSIZE, YSIZE);

  for(y=YSIZE-1;y>=0;y-=1)
  {
    for(x=0;x<XSIZE;x+=1)
    {
      r = 255.0 * frame_buffer[y][x].getRed();
      g = 255.0 * frame_buffer[y][x].getGreen();
      b = 255.0 * frame_buffer[y][x].getBlue();
      if (r > 255.0) r = 255.0;
      if (g > 255.0) g = 255.0;
      if (b > 255.0) b = 255.0;
      printf("%d %d %d\n",(int)r, (int)g, (int)b);
    }
  }
}

void clear_framebuffer()
{
  int x,y;

  for(y=0;y<YSIZE;y+=1)
  {
    for(x=0;x<XSIZE;x+=1)
    {
      frame_buffer[y][x].clear();
    }
  }
}

// The main raytacing entry point.

int main(int argc, const char *argv[])
{
  Scene *scene;
  Vector v;
  int x,y;
  int n;
  DirectionalLight *dl;
  Colour cl;
  Vertex pp;
  double ca, cr, cg,cb;

  srand(30115);

  clear_framebuffer();

  // SETUP SCENE

  // Create a new scene to render
  scene = new Scene();

  // Create and add a directional light to the scene
  v.set(-1.0,-1.0,1.0);
  cl.set(1.0,1.0,1.0,1.0);
  pp.set(-50.0, 50.0, -48.25, 1.0);
  
  dl = new DirectionalLight(v, cl);

  scene->addLight(*dl);

  // Add 10 random spheres to the scene
  for (n = 0; n < 10; n += 1)
  {
    Sphere *s;
    Material *m;
    Vertex p;

    // position
    p.set(frand()-0.5,frand()-0.5,frand()+1.0,1.0);

    // create with random radius
    s = new Sphere(p, frand()/2.0);

    // create new material with shared random Ka and Kd
    m = new Material();

    cr = frand(); cg = frand(); cb = frand(); ca = frand();

    m->ka.red = cr * 0.1;
    m->ka.green = cg * 0.1;
    m->ka.blue = cb * 0.1;
    m->kd.red = cr * 0.5;
    m->kd.green = cg * 0.5;
    m->kd.blue = cb * 0.5;
    m->kr.red =  0.0;
    m->kr.green = 0.0;
    m->kr.blue = 0.0;
    m->ks.red = 0.5;
    m->ks.green =  0.5;
    m->ks.blue = 0.5;
    m->kt.red = 0.0;
    m->kt.green = 0.0;
    m->kt.blue = 0.0;
    m->n = 400.0;

    // set spheres material
    s->setMaterial(m);

    // as sphere to scene
    scene->addObject(*s);
  }

  // RAYTRACE SCENE

  for(y=0;y<YSIZE;y+=1)
  {
    for(x=0;x<XSIZE;x+=1)
    {
      Ray ray;
      float d;

      // Calculate a primary ray
      d = 0.5;
      ray.P.set(0.0,0.0,0.0,1.0);
      ray.D.set((((float)x)/XSIZE)-0.5, (((float)y)/XSIZE)-0.5, d);
      ray.D.normalise();

      // Trace primary ray
      Colour col = scene->raytrace(ray,6);

      // Save result in frame buffer
      frame_buffer[y][x].red = col.red;
      frame_buffer[y][x].green = col.green;
      frame_buffer[y][x].blue = col.blue;
    }
  }

  // OUTPUT IMAGE
 
  write_framebuffer();
}
