#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;
// Function to authenticate a user
bool authenticateUser(const User& user, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string storedUsername = line.substr(0, pos);
        string storedPassword = line.substr(pos + 1);

        if (storedUsername == user.username && storedPassword == user.password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}