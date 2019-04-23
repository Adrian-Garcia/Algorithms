/*
Description:
Dado n (número de nodos), se desea saber cuantos árboles binarios se pueden formar con ellos.

Input:
    Llega en una línea n ( 1 <= n <= 30), cantidad de nodos

Output:
    En una línea con la cantidad de arboles binarios

Sample Input:
    3

Sample Output:
    5 BTrees
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

double howManyTrees(int n) {
    
    // Almacena valores de combinaciones pasadas    
    std::vector<double> v(n,0);
    v.insert(v.begin(), 1);

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            v[i] += v[i-j]*v[j-1];
        }
    }

    // for (int i=0; i<v.size(); i++) {
    //     cout << setprecision(0) << v[i] << endl; 
    // } cout << endl;

    // Regresamos ultimo valor del vector
    return v[n];
}

int main() {
    
    int n = 30;
    
    cin >> n;
    cout << fixed;
    cout << setprecision(0) << howManyTrees(n) << " BTrees" << endl;

    // Termina programa
    return 0;
}
 
