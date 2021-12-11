class Point
{
 private:
  double x;
  double y;
 public:
  double getx();
  double gety();
  void setx(double a);
  void sety(double b);
  Point(); // a constructor which doesn't take any input arguments
  Point(double a, double b); // a constructor which takes 2 double values as input
};
