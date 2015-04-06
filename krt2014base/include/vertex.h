#ifndef _VERTEX_H_
#define _VERTEX_H_

class Vertex {
 public:
  double x;
  double y;
  double z;
  double w;
  Vertex(void);
  void set(double x, double y, double z, double w);
};

#endif
