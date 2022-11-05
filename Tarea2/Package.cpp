#include "Package.h"

Package::Package(int c){
  this->c = 0;
  this->P = multiset<int, greater<int>>();
}
void::Package::insert(int i){
  this->P.insert(i);
}
void::Package::printItems(){
  for (auto it = P.begin(); it != P.end(); ++it)
    cout << *it << " ";
  cout << endl;
}
int Package::getSum(){
  int sum = 0;
  for (auto it = P.begin(); it != P.end(); ++it)
    sum += *it;
  return sum;
}
int Package::size(){
  return P.size();
}

bool operator<(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 < sum2;
}
bool operator>(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 > sum2;
}
bool operator==(const Package& lhs, const Package& rhs){
  if(lhs.P.size() != rhs.P.size())
    return false;

  auto it1 = lhs.P.begin();
  auto it2 = rhs.P.begin();
  while(it1 != lhs.P.end()){
    if(*it1 != *it2)
      return false;
    it1++;
    it2++;
  }
    /*
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
    */
  
  return true;
}
bool operator<=(const Package& lhs, const Package& rhs){
  return lexicographical_compare(rhs.P.begin(), rhs.P.end(), lhs.P.begin(), lhs.P.end());
}
bool operator>=(const Package& lhs, const Package& rhs){
  return lhs.c >= rhs.c;
}

bool operator!=(const Package& lhs, const Package& rhs){
  return !(lhs == rhs);
}

ostream &operator<<(ostream &os, const Package &p){
  for(auto it = p.P.begin(); it != p.P.end(); ++it)
    os << *it << " ";
  return os;
}


