#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"

using namespace std;

// Function to register a new user
void registerUser(const User& newUser, const string& filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    file << newUser.username << ' ' << newUser.password << endl;
    file.close();
}
