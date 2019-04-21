#include <iostream>
using namespace std;
int minimo(int i, int j, int D[50][50],int d[50]){
    D[i][j] = (D[i][i] + D[i+1][j]) + d[j] - d[i-1];
    
    for (int k = i; k < j; k++){
        D[i][j] = min((D[i][k] + D[k+1][j]) + d[j] - d[i-1], D[i][j]);
    }
    return D[i][j];
}
int main() {
    int len, n, c[50];
    cin >> len;
    while (len != 0){
        cin >> n;
        c[0] = 0;
        c[n+1] = len;
        for (int i = 1; i <= n; i++){
            cin >> c[i];
        }
        
        int j, i, diag;
        int D[50][50];
        for (int i = 0; i <= n + 1; i++){
                D[i][i] = 0;
        }
        
        for (diag=1; diag <= n; diag++){
            for (i = 1; i<=n+1-diag; i++) {
                j = i + diag;
                D[i][j] = minimo(i, j, D, c);
                
            }
        }
        cout << "The minimum cutting is "<< D[1][n+1]  << "." << endl;
        cin >> len;
    }
    return 0;
}