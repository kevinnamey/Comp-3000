//Name: Kevin Namey 
//Auburn UserID: kan0010 
//filename: hw2.cpp 
//Development Environment: vim, g++, Linux 
//Compile: g++ -o template hw2.cpp 
//Sample usage: ./template

//Compiler pre-directives (Like libraries and namespaces) 
#include <iostream> //We need this for cin and cout
using namespace std;

//Every program must have one file with a main function. 
int main () 
{ 

	//local variables
	const double SWEETENER_DIET_SODA = 0.001;
	double amountSweetenerDieter;
	double amountSweetenerMouse;
	double weightMouse;
	double weightDieter; 
	int amountDietSoda;

	//Ask for amount of artificial sweetener needed to kill a mouse.
	cout << "What is the amount of artificial sweetener needed to kill a mouse: " << endl;
	cin >> amountSweetenerMouse;

	//Ask for weight of mouse and dieter.
	cout << "What is the weight of the mouse: " << endl;
	cin >> weightMouse;

	cout << "What is the weight of the dieter: " << endl;
	cin >> weightDieter;

	//Calculate amount of diet soda the dieter can drink without dying.
	amountSweetenerDieter = (weightDieter * amountSweetenerMouse) / weightMouse;
	amountDietSoda = amountSweetenerDieter / SWEETENER_DIET_SODA;

	//Display result
	cout << "You can drink " << amountDietSoda << " diet soda without dying as a result.";
 	
	return 0;  
	}
