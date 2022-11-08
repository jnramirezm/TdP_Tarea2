#include <iostream>
#include <string>
#include <vector>
#include "Container_Solver.h"
#include <ctime>


int main(){
    clock_t ti, tf;
    Container_Solver solver = Container_Solver();
    int random, n, cantidad, pesomax, f;
    srand(time(NULL));

    std::cout << "Ingrese 1, si quiere realizar el caso de prueba con 10 elementos y capacidad 7 \nCualquier otro numero si no" << std::endl;
    std::cin >> f;
    if(f == 1){
        solver.capacity = 7;
        for(int i = 0; i < 10; i++){
            random = rand() % 7 + 1;
            solver.items.insert(random);
        }
        ti = clock();
        n = solver.solve();
        std::cout << "Cantidad de contenedores: "<< n << std::endl;
        tf = clock();
        double tiempo = (tf - ti) / (double)CLOCKS_PER_SEC;
        std::cout << "Tiempo de ejecucion: " << tiempo << " segundos." <<std::endl;
        
    }
    else{
        std::cout << "Ingrese la capacidad de los contenedores: ";
        std::cin >> solver.capacity;
        std::cout << "Ingrese cantidad de items a generar: ";
        std::cin >> cantidad;
        std::cout << "Ingrese el peso maximo de los items: ";
        std::cin >> pesomax;
        cout << "\nItems generados: \n" << endl;
        for(int i = 0; i < cantidad; i++){
            random = rand() % pesomax + 1;
            solver.items.insert(random);
            cout << random << " - ";
        }
        cout << endl;
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
        }
    return 0;
}