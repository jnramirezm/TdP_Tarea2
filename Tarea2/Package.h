#include <iostream>
#include <iterator>
#include <set>
#include <stdbool.h>
using namespace std;

class Package{
    public:
        Package(int c);
        int c;
        multiset<int, greater<int>> P;
        void insert(int i);
        void printItems();
        int getSum();
        int size();
        friend bool operator<(const Package& lhs, const Package& rhs);
        friend bool operator>(const Package& lhs, const Package& rhs);
        friend bool operator==(const Package& lhs, const Package& rhs);
        friend bool operator<=(const Package& lhs, const Package& rhs);
        friend bool operator>=(const Package& lhs, const Package& rhs);
        friend bool operator!=(const Package& lhs, const Package& rhs);
        friend ostream &operator<<(ostream &os, const Package &p);
};

