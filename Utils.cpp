#include "Utils.h"
#include <iostream>
#include <algorithm>

using namespace std;

int getIntegerInput(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        cin >> input;

        bool isValid = all_of(input.begin(), input.end(), ::isdigit);

        if (isValid) {
            return stoi(input);
        } else {
            cout << "Enter a valid input.\n";
        }
    }
}
