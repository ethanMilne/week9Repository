#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// ...existing code...
string getMessage() {
    return "this is a string";
}
// ...existing code...

int main() {
	cout << getMessage() << endl;
	cout << "Hello, World!" << endl;

	string userName = "Alice";
	string introduction = "Hello, my name is " + userName + ".";
	cout << introduction << endl;
	return 0;
}
