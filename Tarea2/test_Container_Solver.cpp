#include "Container_Solver.h"
using namespace std;

int main(){
    Container_Solver cs = Container_Solver();
    cs.capacity = 15;
    cs.items.insert(1);
    cs.items.insert(2);
    cs.items.insert(3);
    cs.items.insert(4);
    cs.items.insert(5);
    cs.items.insert(6);
    cs.items.insert(7);
    cs.items.insert(8);
    cs.items.insert(9);
    cs.items.insert(10);
    cs.items.insert(11);
    cs.items.insert(12);
    cs.items.insert(10);
    cs.items.insert(3);
    cs.items.insert(4);
    //cout << cs.heurisic() << endl;
    
   cout << cs.solve() << endl;
    return 0;
}