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
	return 0;
}
