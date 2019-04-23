#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  double pi = 1.5;

  cout << std::fixed << std::showpoint;
  cout << std::setprecision(10) << pi << endl;

  return 0;
}
