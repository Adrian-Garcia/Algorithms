#include <string>
#include <iostream>
using namespace std;

int main(){

    int mat[3][2];
    
    for (int i=0; i<3; i++) {
    	for (int j=0; j<2; j++) {
    		cin >> mat[i][j];
		}
	}
	
	for (int i=0; i<3; i++) {
    	for (int j=0; j<2; j++) {
    		cout <<  mat[i][j] << " ";
		} cout << endl;
	}
    
    return 0;
}
