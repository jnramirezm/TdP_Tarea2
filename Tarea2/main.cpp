#include <iostream>
#include <string>
#include <vector>
#include "Container_Solver.h"
#include <ctime>


int main(){
    clock_t ti, tf;
    Container_Solver solver = Container_Solver();
    int random, n, cantidad;
    
    std::cout << "Ingrese la capacidad del los contenedores: ";
    std::cin >> solver.capacity;
    std::cout << "Ingrese cantidad de items a generar: ";
    std::cin >> cantidad;
    srand(time(NULL));
    for(int i = 0; i < cantidad; i++){
        random = rand() % solver.capacity + 1;
        solver.items.insert(random);
    }
    ti = clock();
    n = solver.solve();
    cout << "Cantidad de contenedores: " << n << endl;
    tf = clock();
    double tiempo = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "Tiempo de ejecucion: " << tiempo << " segundos." <<std::endl;
    return 0;
}