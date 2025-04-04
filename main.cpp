#include <iostream>
#include <string>
using namespace std;

string* updateName(string* namePointer) {
    *namePointer = "Jeff";

    return namePointer;
}

int main() {
    string name = "Dylan";

    string* namePointer = &name;

    cout << namePointer << endl;

    *namePointer = "Bob";

    cout << name << endl;

    updateName(namePointer);

    cout << name << endl;

}
