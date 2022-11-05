#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
#include "Container.h"

class Container_Solver {
public:
    Container_Solver();
    int capacity;
    multiset<int, greater<int>> items;
    int solve();
    int heurisic();
    int sumItems();
    bool checksubSets(int k);
    string createKey(Container c);
};