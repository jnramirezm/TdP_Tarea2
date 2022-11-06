#include "Container.h"
using namespace std;

Container::Container(int capacity, int maxContainers){
    this->capacity = capacity;
    this->maxContainers = maxContainers;
}

Container::Container(){
    this->capacity = 0;
    this->maxContainers = 0;
}

void Container::insert(Package p){
    this->C.insert(p);
}

void Container::printPackages(){
    for (auto it = C.begin(); it != C.end(); ++it)
        cout << *it << " - ";
    cout << endl;
}

bool operator<(const Container& lhs, const Container& rhs){
    int sum1 = 0;
    int sum2 = 0;
    
    for (auto it = lhs.C.begin(); it != lhs.C.end(); ++it){
        Package p = *it;
        sum1 += p.getSum();
    }
    for (auto it = rhs.C.begin(); it != rhs.C.end(); ++it){
        Package p = *it;
        sum2 += p.getSum();
    }
        

    return sum1 < sum2;
}
bool operator>(const Container& lhs, const Container& rhs){
    int sum1 = 0;
    int sum2 = 0;
    for(auto it = lhs.C.begin(); it != lhs.C.end(); ++it){
        Package p = *it;
        sum1 += p.getSum();
    }
    for(auto it = rhs.C.begin(); it != rhs.C.end(); ++it){
        Package p = *it;
        sum2 += p.getSum();
    }
    return sum1 > sum2;
}

bool operator==(const Container& lhs, const Container& rhs){
    if(lhs.C.size() != rhs.C.size())
        return false;
    auto it1 = lhs.C.begin();
    auto it2 = rhs.C.begin();
    while(it1 != lhs.C.end()){
        if(*it1 != *it2)
            return false;
        it1++;
        it2++;
    }
    return true;
}

ostream &operator<<(ostream &os, const Container &c){
    for (auto it = c.C.begin(); it != c.C.end(); ++it)
        os << *it << "  ";
    return os;
}







//3 Paquetes // [1 2 3] [ 4 5 6] [ 7 8 9]
// 1 COntainer con 3 paquetes// [ (1 2 3)(4 5 6)(7 8 9)]
// Branch and Bund, unordered = tabla Hash q contiene containers
// { [(123)(456)(789)][(456)(123)(789)]}