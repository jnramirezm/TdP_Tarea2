#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include "Package.h"

class Container {
public:
    Container();
    Container(int capacity, int maxContainers);
    int capacity;
    int maxContainers;
    multiset<Package, greater<Package>> C;
    void insert(Package p);
    void printPackages();

    friend bool operator<(const Container& lhs, const Container& rhs);
    friend bool operator>(const Container& lhs, const Container& rhs);
    friend bool operator==(const Container& lhs, const Container& rhs);
    friend bool operator<=(const Container& lhs, const Container& rhs);
    friend bool operator>=(const Container& lhs, const Container& rhs);

    friend ostream &operator<<(ostream &os, const Container &c);
    
};