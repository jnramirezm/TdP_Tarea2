#include "Container_Solver.h"
using namespace std;

Container_Solver::Container_Solver(){
    this-> capacity = capacity;
    this-> items = items;
    this-> heuristicsss = Container();
}

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
            Package aux = Package(capacity);
            aux.insert(i);
            container.insert(aux);
        }
    }
    this->heuristicsss = container;
    return container.C.size();
}

int Container_Solver::solve(){
    int a = heurisic();
    int b = sumItems()/capacity;
    cout << "Heuristic: " << a << endl;
    cout << "Optimal: " << b << endl;
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
    heuristicsss.printPackages();
    return a;
}

int Container_Solver::sumItems(){
    int sum = 0;
    for (int i : items){
        sum += i;
    }
    return sum;
}

bool Container_Solver::checksubSets(int k){
    
    // Crear un hash table con todos los subconjuntos de containers
    string fKey;
    int condition;
    vector<Container> containers;
    unordered_map<string,Container> hTable, nexthTable, nextnexthTable;
    //unordered_map<string, Package> hPackage, nexthPackage;
    // multiset de multiset de int
    // multiset de paquetes
    // container
    //unordered_set<Container> hTableSet;
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
                        Container aux3 = aux;
                        aux3.C.erase(aux3.C.find(*it2));
                        aux3.C.insert(aux2);
                        fKey = createKey(aux3);
                        auto inserted = nexthTable.insert(make_pair(fKey,aux3));
                        if(inserted.second){
                            nextnexthTable.insert(make_pair(fKey,aux3));
                            condition = 1;
                        }
                    }
                }  
            };
        if(condition == 0){
            return false;
        }
        hTable.clear();
        hTable = nextnexthTable;
        nextnexthTable.clear();
        nexthTable.clear();
    }
    string sItems = itemstoString(items);
    for(auto it = hTable.begin(); it != hTable.end(); ++it){
        string aux = it->first;
        stringstream ss(aux);
        string token;
        getline(ss, token, ',');
        int sum = stoi(token);
        if(sum == items.size()){
            cout << "Found" << endl;
            heuristicsss = it->second;
            break;
        }

        //it->second.printPackages();
    }
    return true;
}

string Container_Solver::createKey(Container c){
    string key = "";
    int sumsize = 0;
    for(auto it = c.C.begin(); it != c.C.end(); ++it){
        Package aux = *it;
        sumsize += aux.size();
        for(auto it2 = aux.P.begin(); it2 != aux.P.end(); ++it2){
            key += to_string(*it2);
        }
    }
   // sort(key.begin(), key.end());
    string b = to_string(sumsize) + "." + key;
    return b;
}

string Container_Solver::itemstoString(multiset<int, greater<int>> items){
    string key = "";
    for(auto it = items.begin(); it != items.end(); ++it){
        key += to_string(*it);
    }
    sort(key.begin(), key.end());
    return key;
}

string Container_Solver::packageKey(Package p){
    string key = "";
    for(auto it = p.P.begin(); it != p.P.end(); ++it){
        key += to_string(*it) + " ";
    }
    sort(key.begin(), key.end());
    return key;
}


