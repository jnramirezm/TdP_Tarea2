#include "Container.h"

int main(){
    Container c = Container(0,2);
    Package p = Package(0);
    Package p1 = Package(0);

    p.insert(1);
    p.insert(2);
    p1.insert(3);
    p1.insert(1);
    c.insert(p1);
    c.insert(p);
    c.printPackages();
    
    Container c2 = Container(0,2);
    Package p2 = Package(0);
    Package p3 = Package(0);
    p2.insert(1);
    p2.insert(2);
    p3.insert(3);
    p3.insert(1);
    c2.insert(p3);
    c2.insert(p2);
    c2.printPackages();

    cout << (c == c2) << endl;
    return 0;
}