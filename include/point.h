#include <cmath>

struct Coords
{
    Coords(float x, float y, float z) : x(x), y(y), z(z) {}

    float x;
    float y;
    float z;
};

class Point
{
public:
    Point(float x, float y, float z) : x(x), y(y), z(z) {}

    Coords get() const;
    bool set(Coords point);

    void print() const;

    bool valid() const;
    bool equal(const Point& another_point) const;

private:
    float x = NAN;
    float y = NAN;
    float z = NAN;
};