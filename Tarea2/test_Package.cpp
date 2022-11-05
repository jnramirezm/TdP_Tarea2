#include "Package.h"

int main(){
    Package p = Package(0);
    p.insert(1);
    p.insert(2);
    p.insert(3);
    p.insert(4);
    p.printItems();

    Package p1 = Package(0);

    p1.insert(1);
    p1.insert(2);
    p1.insert(3);
    p1.insert(5);
    p.printItems();


    cout << (p == p1) << endl;

    return 0;
}