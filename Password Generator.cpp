#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string generate_password(int length, bool include_lowercase, bool include_uppercase, bool include_numbers, bool include_symbols) {
    // Define the character sets to use in the password
    string lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
    string uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string number_chars = "0123456789";
    string symbol_chars = "!@#$%^&*()_+{}[]|\\:;'\"<>,.?/";

    // Initialize the available character set based on the user's preferences
    string available_chars = "";
    if (include_lowercase) {
        available_chars += lowercase_chars;
    }
    if (include_uppercase) {
        available_chars += uppercase_chars;
    }
    if (include_numbers) {
        available_chars += number_chars;
    }
    if (include_symbols) {
        available_chars += symbol_chars;
    }

    // Generate the password
    string password = "";
    srand(time(NULL)); // Seed the random number generator
    for (int i = 0; i < length; i++) {
        password += available_chars[rand() % available_chars.length()];
    }

    return password;
}

int main() {
    // Get user preferences for the password
    int length;
    bool include_lowercase, include_uppercase, include_numbers, include_symbols;
    cout << "Password Length: ";
    cin >> length;
    cout << "Include Lowercase Letters? (1 for yes, 0 for no): ";
    cin >> include_lowercase;
    cout << "Include Uppercase Letters? (1 for yes, 0 for no): ";
    cin >> include_uppercase;
    cout << "Include Numbers? (1 for yes, 0 for no): ";
    cin >> include_numbers;
    cout << "Include Symbols? (1 for yes, 0 for no): ";
    cin >> include_symbols;

    // Generate the password and display it to the user
    string password = generate_password(length, include_lowercase, include_uppercase, include_numbers, include_symbols);
    cout << "Your Password: " << password << endl;

    return 0;
}

