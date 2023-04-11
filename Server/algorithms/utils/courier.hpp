#include "string"
#include "iosfwd"

using std::string;

class Courier {
  public:
    string id {};
    long double latitude {};
    long double longitude {};
    int speed {};
    int max_distance {};

    Courier () {}

    Courier(string _id, long double _latitude, long double _longitude, int _speed, int _max_distance) : 
      id(_id),
      latitude(_latitude),
      longitude(_longitude),
      speed(_speed),
      max_distance(_max_distance) {}

    friend std::ostream& operator<<(std::ostream&, const Courier&);
};
