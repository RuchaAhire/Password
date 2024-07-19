#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random character from a given character set
char generateRandomChar(const string& charSet) {
    int index = rand() % charSet.size();
    return charSet[index];
}

// Function to generate a random password
string generatePassword(int length, bool useUppercase, bool useDigits, bool useSpecialChars) {
    // Define character sets
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string digits = "0123456789";
    string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    // Build the character set based on user preferences
    string charSet = lowercase;
    if (useUppercase) charSet += uppercase;
    if (useDigits) charSet += digits;
    if (useSpecialChars) charSet += specialChars;

    // Generate the password
    string password;
    for (int i = 0; i < length; ++i) {
        password += generateRandomChar(charSet);
    }

    return password;
}

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    int length;
    bool useUppercase, useDigits, useSpecialChars;

    // Get user input
    cout << "Enter the desired password length: ";
    cin >> length;

    cout << "Include uppercase letters? (1 for yes, 0 for no): ";
    cin >> useUppercase;

    cout << "Include digits? (1 for yes, 0 for no): ";
    cin >> useDigits;

    cout << "Include special characters? (1 for yes, 0 for no): ";
    cin >> useSpecialChars;

    // Generate and display the password
    string password = generatePassword(length, useUppercase, useDigits, useSpecialChars);
    cout << "Generated Password: " << password << endl;

    return 0;
}