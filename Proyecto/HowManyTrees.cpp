/*
Description:
Dado n (número de nodos), se desea saber cuantos árboles binarios se pueden formar con ellos.



Input:

LLega en una línea n ( 1 <= n <= 30), cantidad de nodos

Output:

En una línea con la cantidad de arboles binarios

Sample Input:
3
Sample Output:
5 BTrees
*/

//opcion 1: Rec (no apta la vdd)

#include <iostream>
using namespace std;

long int numTreesREC(int start, int end){
    
    if(start == end) 
        return 1;
    
    if(start > end) 
        return 1;
    
    int res = 0;
    
    for(int i=start; i<=end; i++){
        res += numTreesREC(start, i-1) * numTreesREC(i+1, end);
    } 
    
    return res;
}

int main() {
	
    int n = 19;

    cin >> n;
    cout << numTreesREC(1, n) << endl;

    // Termina programa
    return 0;
}
