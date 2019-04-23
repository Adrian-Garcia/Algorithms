#include <iostream>
#include <vector>
using namespace std;

unsigned long int numTrees(int n){
  if(n <= 1){
    return n;
  }
  vector<unsigned long int>D(n+1,0);
  D[0]=1;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      D[i]+= D[i-j]*D[j-1];
    }
  }
  return D[n];
}

int main() {
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
}