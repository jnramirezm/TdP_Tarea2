#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include "Package.h"

/*-----------------------

Clase que representa un contenedor, el cual contiene un conjunto de paquetes.

-----------------------*/

class Container {
public:
    Container(); // Constructor
    Container(int capacity, int maxContainers); // Sobrecarga de Constructor
    int capacity;   // Capacidad del contenedor
    int maxPackages; // Cantidad maxima de paquetes que puede contener el contenedor
    multiset<Package, greater<Package>> C; // Conjunto de paquetes
    void insert(Package p); // Inserta un paquete en el contenedor
    void printPackages(); // Imprime los paquetes del contenedor
    friend bool operator<(const Container& lhs, const Container& rhs); // Sobrecarga del operador < para comparar contenedores
    friend bool operator>(const Container& lhs, const Container& rhs); // Sobrecarga del operador > para comparar contenedores
    friend bool operator==(const Container& lhs, const Container& rhs); // Sobrecarga del operador == para comparar contenedores
    friend ostream &operator<<(ostream &os, const Container &c); // Sobrecarga del operador << para imprimir contenedores
    
};