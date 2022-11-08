#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <bits/stdc++.h>
#include "Container.h"
/*-------------------------------

Clase que representa el algoritmo para resolver el problema de empaquetamiento de items 
en un contenedor.

--------------------------------*/

class Container_Solver {
public:
    Container_Solver(); // Constructor
    int capacity;  // Capacidad de los Paquetes
    multiset<int, greater<int>> items; // Conjunto de items
    Container solucion; // Contenedor que contiene los paquetes
    int solve(); // Metodo que resuelve el problema
    int heurisic(); // Metodo que realiza una solucion inicial al problema.
    int sumItems(); // Metodo que suma los items del conjunto de items
    bool checksubSets(int k); // Metodo que verifica si es posible tener una solucion la problema con una cantidad k de containers.
    string createKey(Container c); // Metodo que crea una llave para un contenedor
};