#include <iostream>
#include <string>
#include <vector>
#include "Container_Solver.h"
#include <ctime>


int main(){
    clock_t ti, tf;
    Container_Solver solver = Container_Solver();
    /*
    std::cout << "Ingrese la capacidad del los contenedores: ";
    std::cin >> solver.capacidad;
    int cantidad, peso;
    std::cout << "Ingrese cantidad de items: ";
    std::cin >> cantidad;
    std::cout << "(tome en cuenta que el peso no puede sobrepasar la capacidad)" << std::endl;
    std::cout << "Ingrese el peso de los items: ";
    for(int i = 0; i < cantidad; i++){
        if(peso <= solver.capacidad){
            std::cin >> peso;
            solver.items.push_back(peso);
        }else{i--;} //cuando el item no entra en el contenedor, se vuelve a pedir el peso
    }
    */
    std::cout << "Si la heuristica es distinta a (peso total/capacidad) puede ver el proceso" << std::endl;
    std::cout << "Desea ver el poceso? (1 = si / 0 = no) " << std::endl;
    int flag;
    std::cin >> flag;
    ti = clock();
    //solver.solve(flag);
    tf = clock();
    double tiempo = (tf - ti) / (double)CLOCKS_PER_SEC;
    std::cout << "Tiempo de ejecucion: " << tiempo << " segundos." <<std::endl;
    return 0;
}