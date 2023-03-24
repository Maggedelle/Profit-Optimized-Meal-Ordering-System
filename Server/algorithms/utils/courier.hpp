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

    friend std::ostream& operator<<(std::ostream&, const Courier&);
};
