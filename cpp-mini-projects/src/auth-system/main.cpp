#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string username;
    string password;
};

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

// Function to check if a user exists in the file
bool userExists(const string& username, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return false;
    }

    string line;
    while (getline(file, line)) {
        size_t pos = line.find(' ');
        string storedUsername = line.substr(0, pos);
        if (storedUsername == username) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

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

void createFileIfNotExists(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        // File doesn't exist, so create it
        std::ofstream newFile(filename);
        if (newFile.is_open()) {
            std::cout << "File created: " << filename << std::endl;
            newFile.close();
        } else {
            std::cerr << "Error creating file: " << filename << std::endl;
        }
    } else {
        std::cout << "File already exists: " << filename << std::endl;
        file.close();
    }
}


int main() {
    const string filename = "users.txt";
    createFileIfNotExists(filename);
    vector<User> users;

    // Register a new user
    User newUser;
    cout << "Enter username: ";
    cin >> newUser.username;

    // Check if the username already exists
    if (userExists(newUser.username, filename)) {
        cout << "Username already exists. Please choose a different username." << endl;
        return 1;
    }

    cout << "Enter password: ";
    cin >> newUser.password;

    // Save the new user to the file
    registerUser(newUser, filename);

    cout << "User registered successfully." << endl;

    // Login
    User loginUser;
    cout << "Enter username for login: ";
    cin >> loginUser.username;

    cout << "Enter password for login: ";
    cin >> loginUser.password;

    // Authenticate the user
    if (authenticateUser(loginUser, filename)) {
        cout << "Login successful. Welcome, " << loginUser.username << "!" << endl;
    } else {
        cout << "Login failed. Invalid username or password." << endl;
    }

    return 0;
}