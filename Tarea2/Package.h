#include <iostream>
#include <iterator>
#include <set>
#include <stdbool.h>

using namespace std;

/*------------------

Clase que representa un paquete, el cual contiene un conjunto de items.

--------------------*/

class Package{
    public:
        Package(int c);                   // Constructor
        int c;                            // Capacidad del paquete 
        multiset<int, greater<int>> P;    // Conjunto de items
        void insert(int i);               // Inserta un item en el paquete
        void printItems();                // Imprime los items del paquete
        int getSum();                     // Suma los items del paquete
        int size();                       // Retorna la cantidad de items que contiene el paquete
        friend bool operator<(const Package& lhs, const Package& rhs); // Sobrecarga del operador < para comparar paquetes
        friend bool operator>(const Package& lhs, const Package& rhs); // Sobrecarga del operador > para comparar paquetes
        friend bool operator==(const Package& lhs, const Package& rhs); // Sobrecarga del operador == para comparar paquetes
        friend bool operator<=(const Package& lhs, const Package& rhs); // Sobrecarga del operador <= para comparar paquetes 
        friend bool operator!=(const Package& lhs, const Package& rhs); // Sobrecarga del operador != para comparar paquetes
        friend ostream &operator<<(ostream &os, const Package &p); // Sobrecarga del operador << para imprimir paquetes
};

