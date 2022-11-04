#include <iostream>
#include <iterator>
#include <set>
#include <stdbool.h>
using namespace std;

class Package{
    public:
        Package(int c);
        int c;
        multiset<int, less<int>> P;
        void insert(int i);
        void printItems();
        friend bool operator<(const Package& lhs, const Package& rhs);
        friend bool operator>(const Package& lhs, const Package& rhs);
        friend bool operator==(const Package& lhs, const Package& rhs);
        friend bool operator<=(const Package& lhs, const Package& rhs);
        friend bool operator>=(const Package& lhs, const Package& rhs);
        friend ostream &operator<<(ostream &os, const Package &p);


    
};

