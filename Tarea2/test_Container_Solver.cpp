#include "Container_Solver.h"
using namespace std;

int main(){
    Container_Solver cs = Container_Solver();
    cs.capacity = 20;
    cs.items = {1,1,1,1,1,3,3,3,3,3,4,4,4,4,4,7,7,7,7,7,8,8,8,8,8,9,9,9,9,9}; 
    //cs.items = {1,2,3,4,5,6,7,8,9,10};
    cout << cs.solve() << endl;
    return 0;
}