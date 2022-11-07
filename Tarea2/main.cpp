#include <iostream>
#include <string>
#include <vector>
#include "Container_Solver.h"
#include <ctime>


int main(){
    clock_t ti, tf;
    Container_Solver solver = Container_Solver();
    int random, n, cantidad, pesomax;
    
    std::cout << "Ingrese la capacidad de los contenedores: ";
    std::cin >> solver.capacity;
    std::cout << "Ingrese cantidad de items a generar: ";
    std::cin >> cantidad;
    std::cout << "Ingrese el peso maximo de los items: ";
    std::cin >> pesomax;
    srand(time(NULL));
    for(int i = 0; i < cantidad; i++){
        random = rand() % pesomax + 1;
        solver.items.insert(random);
    }
    ti = clock();
    std::cout << std::endl;
    n = solver.solve();
    if(n == -1){
        std::cout << "No existe solucion. \nEl tamano de un item es mayor que la capacidad \n" << std::endl;
    }else{
    cout << "Cantidad de contenedores: " << n << "\n" << endl;
    }
    tf = clock();
    double tiempo = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "Tiempo de ejecucion: " << tiempo << " segundos." <<std::endl;
    return 0;
}