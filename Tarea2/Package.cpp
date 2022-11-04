#include "Package.h"

Package::Package(int c){
  this->c = 0;
}
void::Package::insert(int i){
  this->P.insert(i);
}
void::Package::printItems(){
  for (auto it = P.begin(); it != P.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

bool operator<(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 > sum2;
}
bool operator>(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 < sum2;
}
bool operator==(const Package& lhs, const Package& rhs){
  if(lhs.P.size() != rhs.P.size())
    return false;
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  
  return sum1 == sum2;
}
bool operator<=(const Package& lhs, const Package& rhs){
  return lexicographical_compare(rhs.P.begin(), rhs.P.end(), lhs.P.begin(), lhs.P.end());
}
bool operator>=(const Package& lhs, const Package& rhs){
  return lhs.c >= rhs.c;
}
ostream &operator<<(ostream &os, const Package &p){
  for(auto it = p.P.begin(); it != p.P.end(); ++it)
    os << *it << " ";
  return os;
}


