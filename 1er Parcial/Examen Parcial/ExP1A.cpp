/*
  Matricula:	
  Nombre:		
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool iguales(vector<int> &d, int k){

	bool flag = false;
  	map<int, int> miMap;
  	map<int, int>::iterator it;

	for (int i=0; i<d.size() && !flag; i++) {
		
		//Busca el elemento
		it = miMap.find(d[i]);

		if (it != miMap.end()) { 	//Fue encontrado
			if (i - it->second <= k) {
				flag = true;
			} else {
				it->second = i;
			}
		} else {					//No fue encontrado
			
			//Creamos nuevo elemento
			pair <int, int> miPar(d[i], i);
			miMap.insert(miPar);
		}
	}

	return flag;
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  cout << (iguales(datos, k)? "YES" : "NO") <<endl;
}

/*
Ejemplo 1
4 3
1 2 3 1

Ejemplo 2
4 1
1 0 1 1

Ejmplo 3
6 2
1 2 3 1 2 3
 
*/
