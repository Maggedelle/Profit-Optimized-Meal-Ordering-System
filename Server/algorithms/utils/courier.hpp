#include "string"
#include "iosfwd"

using std::string;

class Courier {
  public:
    string id {};
    long double latitude {};
    long double longitude {};
    int speed {};

    friend std::ostream& operator<<(std::ostream&, const Courier&);
};
