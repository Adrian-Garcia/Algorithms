#include <iostream>
#include <vector>
using namespace std;

int N = 2;

void multiply(int A[2][2], int B[2][2], int C[2][2]) 
{ 
  for (int i = 0; i < N; i++) 
  { 
    for (int j = 0; j < N; j++) 
    { 
      C[i][j] = 0; 
      for (int k = 0; k < N; k++) 
      { 
        C[i][j] += A[i][k]*B[k][j]; 
      } 
    } 
  } 
} 


int main() {
    
  // N = 2;

  int A[N][N];
  int B[N][N];
  int C[N][N] = {0};

  A[0][0] = 1;
  A[0][1] = 3;
  A[1][0] = 5;
  A[1][1] = 7;

  C[0][0] = 2;
  C[0][1] = 4;
  C[1][0] = 6;
  C[1][1] = 8;

  multiply(A, B, C);

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      cout << C[i][j] << "\t";
    }
    cout << endl;
  }
}