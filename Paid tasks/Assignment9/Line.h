class Line
{
 private:
  Point a;
  Point b;
 public:
  Line(Point& p1, Point& p2);
  Line(double x1, double y1, double x2, double y2);
  double length(); // a method to return the length of the line
};
