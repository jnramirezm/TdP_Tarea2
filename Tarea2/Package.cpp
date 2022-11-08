#include "Package.h"

/*-------------------

Clase que representa un paquete, el cual contiene un conjunto de items.

-------------------*/

/*
Descripcion: Constructor de la clase Package
Parametros: int capacity
Retorno: N/A
*/
Package::Package(int c){
  this->c = 0;
  this->P = multiset<int, greater<int>>();
}

/*
Descripcion: Inserta un item en el paquete
Parametros: int item
Retorno: N/A
*/
void::Package::insert(int i){
  this->P.insert(i);
}

/*
Descripcion: Imprime los items del paquete
Parametros: N/A
Retorno: N/A / Imprime los items por consola
*/
void::Package::printItems(){
  for (auto it = P.begin(); it != P.end(); ++it)
    cout << *it << " ";
  cout << endl;
}

/*
Descripcion: Suma los items del paquete
Parametros: N/A
Retorno: int suma
*/
int Package::getSum(){
  int sum = 0;
  for (auto it = P.begin(); it != P.end(); ++it)
    sum += *it;
  return sum;
}

/*
Descripcion: retorna la cantidad de items que contiene el paquete
Parametros: Package p
Retorno: int size
*/
int Package::size(){
  return P.size();
}

/*
Descripcion: Crea una llave para el paquete
Parametros: N/A
Retorno: string key
*/
string Package::getKey(){
  string key = "";
  for (auto it = P.begin(); it != P.end(); ++it){
    key += to_string(*it);
  }
  sort(key.begin(), key.end());
  return key;
}

/*
Descripcion: Metodo necesario para el uso de Multiset, verifica si un paquete es menor que otro calculando 
el valor de la suma de sus items.
Parametros: Package lhs y Package rhs
Retorno: bool
*/
bool operator<(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 < sum2;
}

/*
Descripcion: Metodo necesario para el uso de Multiset, verifica si un paquete es mayor que otro calculando
el valor de la suma de sus items.
Parametros: Package lhs y Package rhs
Retorno: bool
*/
bool operator>(const Package& lhs, const Package& rhs){
  int sum1 = 0;
  for(auto it = lhs.P.begin(); it != lhs.P.end(); ++it)
    sum1 += *it;
  int sum2 = 0;
  for(auto it = rhs.P.begin(); it != rhs.P.end(); ++it)
    sum2 += *it;
  return sum1 > sum2;
}

/*
Descripcion: Metodo necesario para el uso de Multiset, verifica si un paquete es igual que otro, primeramente
verificando que contengan el mismo numero de items, luego verificando que los items sean iguales y con mismo orden.
Parametros: Package lhs y Package rhs
Retorno: bool
*/
bool operator==(const Package& lhs, const Package& rhs){
  if(lhs.P.size() != rhs.P.size())
    return false;

  auto it1 = lhs.P.begin();
  auto it2 = rhs.P.begin();
  while(it1 != lhs.P.end()){
    if(*it1 != *it2)
      return false;
    it1++;
    it2++;
  }
  return true;
}

/*
Descripcion: Metodo necesario para el uso de Multiset, verifica si un paquete es menor o igual que otro,
verificando si tienen los mismos items y en el mismo orden y la suma de estos.
Parametros: Package lhs y Package rhs
Retorno: bool
*/
bool operator<=(const Package& lhs, const Package& rhs){
  return lexicographical_compare(rhs.P.begin(), rhs.P.end(), lhs.P.begin(), lhs.P.end());
}

/*
Descripcion: Metodo necesario para el uso de Multiset, verifica si un paquete es distinto que otro, verificando
si tienen los mismos items y en el mismo orden.
Parametros: Package lhs y Package rhs
Retorno: bool
*/
bool operator!=(const Package& lhs, const Package& rhs){
  return !(lhs == rhs);
}

/*
Descripcion: Metodo que imprime los items de un paquete utilizando cout
Parametros: ostream& os y Package p
Retorno: ostream& os
*/
ostream &operator<<(ostream &os, const Package &p){
  for(auto it = p.P.begin(); it != p.P.end(); ++it)
    os << *it << " ";
  return os;
}


