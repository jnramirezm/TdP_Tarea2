#include "Container.h"
using namespace std;

Container::Container(int capacity){
    this->capacity = capacity;
}

void Container::insert(Package p){
    C.insert(p);
}

void Container::printPackages(){

    for (auto it = C.begin(); it != C.end(); ++it)
        cout << *it << " - ";
    cout << endl;
}






//3 Paquetes // [1 2 3] [ 4 5 6] [ 7 8 9]
// 1 COntainer con 3 paquetes// [ (1 2 3)(4 5 6)(7 8 9)]
// Branch and Bund, unordered = tabla Hash q contiene containers
// { [(123)(456)(789)][(456)(123)(789)]}