#include <cstring>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


bool access(const string& userName, const string& password) {
    string line;
    ifstream myFile("database.txt");


    while (getline(myFile, line)) {
        //find the comma in the line
        size_t commaPos = line.find(',');

        // if the comma is not at the end of the string
        if (commaPos != string::npos) {
            // the part before the comma
            string fileUser = line.substr(0, commaPos);

            // the part after the comma
            string filePass = line.substr(commaPos + 1);


            if (fileUser == userName && filePass == password) {
                return true;
            }

        }
        else {
            cout << line << endl;
        }

    }
    myFile.close();
    return false;
}

int main() {
    cout << "Welcome!\n1: Login\n2: Create new account\n";
    string loginOrNew, username, password;
    cin >> loginOrNew;

    if (loginOrNew == "1") {
        bool retry = false;
        do {
            cout << "Username: ";
            cin >> username;

            cout << "Password: ";
            cin >> password;

            if (access(username, password)) {
                cout << "Logged in!\n";
            }

            else {
                cout << "Your username or password is incorrect!\n";

                cout << "Do you want to retry logging in? (Y/n)\n";
                string loginRetry;
                cin >> loginRetry;
                if (loginRetry != "n") {
                    retry = true;
                }
                else {
                    cout << "Exiting system!\n";
                    exit(0);
                }
            }
        } while (retry);

    }

    if (loginOrNew == "2") {
        cout << "Username: ";
        cin >> username;

        cout << "Password: ";
        cin >> password;


        ofstream MyFile("database.txt", ios::app);


        MyFile << username << "," << password << "\n";

        MyFile.close();

        cout << "Account created successfully!\n";
    }

    cout << "Account username: " << username;
}
