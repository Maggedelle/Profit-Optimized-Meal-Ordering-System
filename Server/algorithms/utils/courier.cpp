#include "courier.hpp"
#include "iostream"

std::ostream& operator<<(std::ostream& os, const Courier& courier){
      os << courier.id << ", " << courier.latitude << ", " << courier.longitude << ", " << courier.speed;
      return os;
 }
