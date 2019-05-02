#include <string>
#include <iostream>
using namespace std;

int main(){

    int numCasos;
    cin >> numCasos;
    long tam1, tam2;
    string s1, s2;

    for(int i = 0; i < numCasos; i++){
        cin >> s1 >> s2;
        tam1 = s1.length();
        tam2 = s2.length();
        int mat[tam1+1][tam2+1];

        for (int r = 0; r <= tam1; r++){
            for(int c = 0; c <= tam2; c++){
                if( r == 0 || c == 0)
                    mat[r][c] = 0;
                else if (s1[r-1] == s1[c-1])
                    mat[r][c] = mat[r-1][c-1] +1;
                else
                    mat[r][c] = max(mat[r][c-1], mat[r-1][c]);
            }
        }
        cout << endl<< "Case " << i+1 << ":" << mat[tam1][tam2];
        cout << endl;
    }
    return 0;
}