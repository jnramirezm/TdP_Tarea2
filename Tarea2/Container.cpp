#include "Container.h"
using namespace std;

/*---------------------

Clase que representa un contenedor, el cual contiene un conjunto de paquetes.

----------------------*/

/*
Descripcion: Constructor de la clase Container
Parametros: int capacity, int maxPackages
Retorno: N/A
*/
Container::Container(int capacity, int maxPackages){
    this->capacity = capacity;
    this->maxPackages = maxPackages;
}

/*
DescripcionL Constructor de la clase Container
Parametros: N/A
Retorno: N/A
*/
Container::Container(){
    this->capacity = 0;
    this->maxPackages = 0;
}

/*
Descripcion: Inserta un paquete en el contenedor
Parametros: Package p
Retorno: N/A
*/
void Container::insert(Package p){
    this->C.insert(p);
}

/*
Descripcion: Imprime los paquetes del contenedor
Parametros: N/A
Retorno: N/A / Imprime los paquetes por consola
*/
void Container::printPackages(){
    for (auto it = C.begin(); it != C.end(); ++it)
        cout << *it << "  ";
    cout << "\n" <<endl;
}

/*
Descripcion: Sobrecarga del operador < para comparar contenedores. (Necesario para uso de multiset)
Parametros: Container lhs, Container rhs
Retorno: bool
*/
bool operator<(const Container& lhs, const Container& rhs){
    int sum1 = 0;
    int sum2 = 0;
    
    for (auto it = lhs.C.begin(); it != lhs.C.end(); ++it){
        Package p = *it;
        sum1 += p.getSum();
    }
    for (auto it = rhs.C.begin(); it != rhs.C.end(); ++it){
        Package p = *it;
        sum2 += p.getSum();
    }
        

    return sum1 < sum2;
}

/*
Descripcion: Sobrecarga del operador > para comparar contenedores. (Necesario para uso de multiset)
Parametros: Container lhs, Container rhs
Retorno: bool
*/
bool operator>(const Container& lhs, const Container& rhs){
    int sum1 = 0;
    int sum2 = 0;
    for(auto it = lhs.C.begin(); it != lhs.C.end(); ++it){
        Package p = *it;
        sum1 += p.getSum();
    }
    for(auto it = rhs.C.begin(); it != rhs.C.end(); ++it){
        Package p = *it;
        sum2 += p.getSum();
    }
    return sum1 > sum2;
}

/*
Descripcion: Sobrecarga del operador == para imprimir contenedores. (Necesario para uso de multiset)
Parametros: Container lhs, Container rhs
Retorno: bool
*/
bool operator==(const Container& lhs, const Container& rhs){
    if(lhs.C.size() != rhs.C.size())
        return false;
    auto it1 = lhs.C.begin();
    auto it2 = rhs.C.begin();
    while(it1 != lhs.C.end()){
        if(*it1 != *it2)
            return false;
        it1++;
        it2++;
    }
    return true;
}

/*
Descripcion: Sobrecarga del operador << para imprimir contenedores.
Parametros: ostream& os, Container c
Retorno: ostream& os
*/
ostream &operator<<(ostream &os, const Container &c){
    for (auto it = c.C.begin(); it != c.C.end(); ++it)
        os << *it << "  ";
    return os;
}