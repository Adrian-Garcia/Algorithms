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
using namespace std;

long int howManyTrees(int start, int end){
    
  	int res = 0;
  
    if(start == end) 
        return 1;
    
    else if(start > end) 
        return 1;
    
    for(int i=start; i<=end; i++){
        res += howManyTrees(start, i-1) * howManyTrees(i+1, end);
    } 
    
    return res;
}

int main() {
	
    int n = 3;

    cin >> n;
    cout << howManyTrees(1, n) << " BTrees" << endl;

    // Termina programa
    return 0;
}

