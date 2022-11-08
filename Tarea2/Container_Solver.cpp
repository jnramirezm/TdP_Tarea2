#include "Container_Solver.h"
using namespace std;

/*----------------------------------

Clase que representa el algoritmo para resolver el problema de empaquetamiento de items
en un contenedor.

----------------------------------*/

/*
Descripcion: Constructor de la clase Container_Solver
Parametros: N/A
Retorno: N/A
*/
Container_Solver::Container_Solver(){
    this-> capacity = capacity;
    this-> items = items;
    this-> solucion = Container();
}

/*
Descripcion: Metodo que realiza una solucion inicial al problema, metodo First Fit.
Parametros: N/A
Retorno: int suma
*/
int Container_Solver::heurisic(){

    int res;
    Container container = Container(capacity, items.size());
    Package p = Package(capacity);
    container.insert(p);

    for (int i : items){
        res = 0;
        
        for(auto it = container.C.begin(); it != container.C.end(); ++it){
            Package aux = *it;
            if (aux.getSum() + i <= capacity){
                aux.insert(i);
                container.C.erase(container.C.find(*it));
                container.C.insert(aux);
                res = 1;
                break;
            }  
        }
        if(res == 0){
            if( i > capacity){
                return -1;
            }
            Package aux = Package(capacity);
            aux.insert(i);
            container.insert(aux);
        }
    }
    this->solucion = container;
    return container.C.size();
}

/*
Descripcion: Metodo que busca la cantidad de contenedores optima para resolver el problema.
Parametros: N/A
Retorno: int Cantidad optima de paquetes dentro del contenedor.
*/
int Container_Solver::solve(){
    int a = heurisic();
    if(a == -1){
        return -1;
    }
    int b = sumItems()/capacity;
    cout << "Heuristic: " << a << endl;
    cout << "Optimal: " << b << "\n" << endl;
    while(a > b){
        int k = (a+b)/2;
        if(checksubSets(k)){
            a = k;
        }else{
            if( b != k){
                b = k;
            }
            else{
                b++;
            }
        }
    }
    solucion.printPackages();
    return a;
}

/*
Descripcion: Metodo que suma el total del peso de los items.
Parametros: N/A
Retorno: int suma
*/
int Container_Solver::sumItems(){
    int sum = 0;
    for (int i : items){
        sum += i;
    }
    return sum;
}

/*
Descripcion: Metodo que verifica si es posible empaquetar los items en k paquetes.
Parametros: int k
Retorno: bool
*/
bool Container_Solver::checksubSets(int k){
    string fKey;
    int condition;
    unordered_map<string,Container> hTable, nexthTable, auxNexthTable;
    unordered_set<string> packageCreated;
    Container container = Container(capacity,k);

    for(int i = 0 ; i < k ; i++){
        Package p = Package(capacity);
        container.insert(p);
    }
    
    fKey = createKey(container);
    hTable.insert(make_pair(fKey,container));
    for (int i : items){
        condition = 0;
            for (auto it = hTable.begin(); it != hTable.end(); ++it){
                Container aux = it->second;
                for(auto it2 = aux.C.begin(); it2 != aux.C.end(); ++it2){
                    Package aux2 = *it2;
                    if (aux2.getSum() + i <= capacity){
                        aux2.insert(i);
                        if(packageCreated.find(aux2.getKey()) == packageCreated.end()){ // Se busca si el paquete ya fue creado
                            packageCreated.insert(aux2.getKey());
                            Container aux3 = aux;
                            aux3.C.erase(aux3.C.find(*it2));    // Se elimina el paquete que se va a modificar
                            aux3.C.insert(aux2);                // se inserta el paquete modificado al container aux
                            fKey = createKey(aux3);
                            auto inserted = nexthTable.insert(make_pair(fKey,aux3));
                            if(inserted.second){    // Verifica si se inserto el elemento y se inserta en la tabla verdadera
                                auxNexthTable.insert(make_pair(fKey,aux3));
                                condition = 1;
                             }
                        }
                    }
                    if(it2 == --aux.C.end()){   // se limpia la tabla de nodos de packages
                        packageCreated.clear();
                    }
                }  
            };
        if(condition == 0){
            return false;
        }
        hTable.clear();         // Se sobreescribe la tabla hash y se limpian las auxiliares
        hTable = auxNexthTable;
        auxNexthTable.clear();
        nexthTable.clear();
    }
    for(auto it = hTable.begin(); it != hTable.end(); ++it){
        string aux = it->first;
        stringstream ss(aux);
        string token;
        getline(ss, token, ',');
        int sum = stoi(token);
        if(sum == (int)items.size()){
            cout << "Found" << endl;
            solucion = it->second;
            return true;
        }
    }
    return true;
}

/*
Descripcion: Metodo que crea una llave unica para el hash table de un contenedor.
Parametros: Container container
Retorno: string key
*/
string Container_Solver::createKey(Container c){
    string key = "";
    int sumsize = 0;
    for(auto it = c.C.begin(); it != c.C.end(); ++it){
        Package aux = *it;
        sumsize += aux.size();
        for(auto it2 = aux.P.begin(); it2 != aux.P.end(); ++it2){
            string aux2 = to_string(*it2);
            key += aux2;
        }
    }
    string b = to_string(sumsize) + "." + key;
    return b;
}



