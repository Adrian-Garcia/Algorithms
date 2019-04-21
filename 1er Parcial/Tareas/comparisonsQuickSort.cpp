#include <iostream>
#include <vector>

using namespace std;

int contComp=0;

void Particion (vector <int> &d, int ini, int fin, int &pivote){
    
    int elempivote = d[ini]; 
    int j = ini;
    int aux;

    for (int i=ini+1; i<=fin; i++) {
        
        contComp++;
        if (d[i] < elempivote) {
            
            j = j+1;
            
            // Intercambia d[i] con d[j]
            aux = d[i];
            d[i] = d[j];
            d[j] = aux;
        }
    }
    pivote = j;
    
    //Intercambia d[inicio] con d[pivote]
    aux = d[ini];
    d[ini] = d[pivote];
    d[pivote] = aux;

}

void QuickSort (vector<int> &d, int ini, int fin){
    if (ini < fin) {

        int pivote = ini;

        Particion (d, ini, fin, pivote);
        QuickSort(d, ini, pivote-1);
        QuickSort(d, pivote+1, fin);
    }
}



//void Particion(vector<int> &d, int ini, int fin, int &pivote){};
//void QuickSort(vector<int> &d, int ini, int fin){};

int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++) {
		cin>>datos[i];
	}
	QuickSort(datos, 0, n-1);

	cout << endl << contComp << endl;
	
	for (int i=0; i<n; i++){
		cout<<datos[i]<< " ";
	} 
	cout << endl;
	
}
