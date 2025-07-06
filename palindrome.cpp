#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to remove non-alphanumeric characters and convert to lowercase
string sanitizeInput(const string& input) {
    string cleaned;
    for (char ch : input) {
        if (isalnum(ch))
            cleaned += tolower(ch);
    }
    return cleaned;
}

// Function to check if a string is a palindrome
bool isPalindromeString(const string& input) {
    string cleaned = sanitizeInput(input);
    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());
    return cleaned == reversed;
}

// Function to check if a number is a palindrome
bool isPalindromeNumber(int num) {
    int original = num, reversed = 0;
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return original == reversed;
}

// Main menu
void displayMenu() {
    cout << "\n===== Palindrome Checker =====\n";
    cout << "1. Check palindrome (string)\n";
    cout << "2. Check palindrome (number)\n";
    cout << "3. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        cin.ignore(); // flush newline character

        switch (choice) {
            case 1: {
                string input;
                cout << "Enter a string: ";
                getline(cin, input);

                if (isPalindromeString(input))
                    cout << "✅ It is a palindrome string.\n";
                else
                    cout << "❌ Not a palindrome string.\n";
                break;
            }
            case 2: {
                int number;
                cout << "Enter a number: ";
                cin >> number;

                if (number < 0) {
                    cout << "❌ Negative numbers are not considered palindromes.\n";
                    break;
                }

                if (isPalindromeNumber(number))
                    cout << "✅ It is a palindrome number.\n";
                else
                    cout << "❌ Not a palindrome number.\n";
                break;
            }
            case 3:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 3);

    return 0;
}
