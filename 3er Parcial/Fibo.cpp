#include <iostream> 

using namespace std;

int fibo(int x) {
    
	if(x < 2) {
        return x;
    }

    return fibo(x-2) + fibo(x-1);
}

int main()
{

  for(int i = 0; i < 40; i++)
  {
      cout << "Fibo " << i+1 << " is: " << fibo(i) << endl;
  }

}
