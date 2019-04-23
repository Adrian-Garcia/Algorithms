#include <iostream>
<<<<<<< HEAD
using namespace std;

int CN(int n){
  int Cn =0;
  // base case
  if(n==0) // empty tree
  {
    return 1;
  }
  for(int i=1;i<n+1;i++)
  {
    Cn+= CN(i-1)*CN(n-i);
  }
  return Cn;
}

int main(){
  int n = 19;
  cout<<"Enter number of nodes: ";
//  cin>>n;
  cout<<n<<endl;
  int trees=CN(n);
  cout<<trees<<" binary search trees are there for "<<n<<" nodes"<<endl;
  return 0; 
=======
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
>>>>>>> dev
}

int main() {
    int n;
    cin >> n;
    cout << numTrees(n) << endl;
}