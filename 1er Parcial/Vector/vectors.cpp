#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//Vectors part 2
int main () {

	//Regular array, it's size cannot change
	int myArray[3] = {10,20,30};

	//Vector, dinamic memory, you can change it's size
	std::vector<int> vector(10);	//Ten values in the vector
	std::vector<int> myVector;		//No values in the vector

	//Add 
	myVector.push_back(10);	//Push 10 to the last direction of the vector
	myVector.push_back(20);	//Push 20 to the last direction of the vector
	myVector.push_back(30);	//Push 30 to the last direction of the vector
	myVector.push_back(40);	//Push 40 to the last direction of the vector

	//Size of the vector
	cout << "myVector size = " << myVector.size() << endl;

	//myVector[]
	cout << "\nDisplay vector with myVector[] = ";
	for (int i=0; i<myVector.size(); i++)
		cout << myVector[i] << " ";
	
	//myVector.at()
	cout << "\nDisplay vector with myVector.at() = ";
	for (int i=0; i<myVector.size(); i++)
		cout << myVector.at(i) << " ";

	//Delete
	cout << "\n\nDelete myVector.begin()";
	cout << "\nIt contained the value of 10" << endl;
	myVector.erase(myVector.begin());	//We need to use an iterator
	for (int i=0; i<myVector.size(); i++) 
		cout << myVector.at(i) << " ";
	cout << "\nNew size = " << myVector.size();

	cout << "\n\nDelete myVector.begin() + 2";
	cout << "\nIt contained the value of 40" << endl;
	myVector.erase(myVector.begin()+2);	//We need to use .begin()+2
	for (int i=0; i<myVector.size(); i++) 
		cout << myVector.at(i) << " ";
	cout << "\nNew size = " << myVector.size();

	cout << "\n\nDelete the value 30" << endl;
	//We need to use the iterators .begin() .end() and the value to delete
	myVector.erase(std::remove(myVector.begin(), myVector.end(), 30), myVector.end());	
	for (int i=0; i<myVector.size(); i++) 
		cout << myVector.at(i) << " ";
	cout << "\nNew size = " << myVector.size();	

	cout << "\n\nDelete all the values o the vector";
	myVector.clear();
	cout << "\nIs myVector empty = " << myVector.empty() << endl;

	cout << endl << endl;
	return 0;
}