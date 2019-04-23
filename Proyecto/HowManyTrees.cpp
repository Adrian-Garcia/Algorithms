/*
Description:
Dado n (n�mero de nodos), se desea saber cuantos �rboles binarios se pueden formar con ellos.

Input:
    Llega en una l�nea n ( 1 <= n <= 30), cantidad de nodos

Output:
    En una l�nea con la cantidad de arboles binarios

Sample Input:
    3

Sample Output:
    5 BTrees
*/
#include <iostream>
using namespace std;

long int howManyTrees(int n) {
    
    int res = 0;
  
    if(!n) 
        return 1;
    
    for (int i=0; i<n; i++) {
        res += howManyTrees(i)*howManyTrees(n-i-1);
    }
    
    return res;
}

int main() {
    
    int n = 30;

    // cin >> n;
    cout << howManyTrees(n) << " BTrees" << endl;

    // Termina programa
    return 0;
}
 
