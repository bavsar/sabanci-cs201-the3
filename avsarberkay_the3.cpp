#include <iostream>
#include <string>
using namespace std;



// Berkay Avsar 27782

int develop;
// Function to check if all characters in a string are the same
bool allSame(string input) {
    bool result;
    if (input.length() > 0) {
       result = input.find_first_not_of(input.at(0)) == string::npos;
    }
    else {
        result = false;
    }
    return result;
}
// Function to check if one string contains another
bool doNotContain(string source, string search) {
    if (source.find(search) == string::npos) {
        return true;
    }
    return false;
}
// Function to check string lengths
bool stringLengthComparison(string a, string b) {
    if (a.length() < b.length()) {
        return false;
    }
    return true;
}
// Function to transform input to source string
string getString(string input) {
    string newInput;
    if (input.at(0) != 3) {
        newInput = input.substr(2, input.length()-1);
    }
    return newInput;
}
// Function to get the First Character of a string
char getFirstChar(string input) {
    char firstChar = input.at(0);
    return firstChar;
}
// Function for source input check
bool sourceInputCheck(string input) {
    for (int i = 0; i < input.length(); i++) {
        char ch = input.at(i);
        if (!isalpha(ch)) {
            return false;
        }
    }
    if (getString(input) == ""){
        return false;
    }
    return true;
}
// Function for search input check
bool searchInputCheck(string input) {
    if (input.length() <= 0) {
        cout << "Wrong input format! Try again." << endl;
        return false;
    }
    else if (input.length() == 1 && input.at(0) == '?') {
        cout << "Wrong input format! Try again." << endl;
        return false;
    }
    for (int i = 0; i < input.length(); i++) {
        char ch = input.at(i);
        if (ch != '?' && !isalpha(ch)) {
            cout << "Wrong input format! Try again." << endl;
            return false;
        }
        if (ch == ' ') {
            cout << "Wrong input format! Try again." << endl;
            return false;
        }
    }
    if (allSame(input) && (input.at(0) == '?')) {
        cout << "Wrong input format! Try again." << endl;
        return false;
    }
    return true;
}

int main() {
    
    string input;
    string source;
    string search;
    string newSearch;
    int counter = 0;
    int x;
    int y;
    
    cout << "This program searches a search string in a source string with the option of wildcards." << endl;
    cout << endl;
    cout << "Example inputs with their meaning in parentheses:" << endl;
    cout << "1 thislectureisawesome (to enter a new source string)" << endl;
    cout << "2 lecture (to enter a new search string)" << endl;
    cout << "2 t?r? (to enter a search string with wildcards)  ";
    cout << endl;
    cout << "3 (to exit the program)" << endl;
    cout << endl;
    
    while (true) {
        
        cout << "Enter your choice and string: ";
        getline(cin, input);

        if (input == "3") {
            cout << "See you!" << endl;
            return 0;
        }
        if (counter > 0) {
            if (input.length() <= 0) {
                cout << "Wrong input format! Try again." << endl;
            }
            else if (getFirstChar(input) == '1') {
                source = getString(input);
            }
            else if (getFirstChar(input) == '2') {
                search = getString(input);
            }
            else {
                cout << "Choice can be 1, 2 or 3! Try again." << endl;
            }
        }
        
        else if (counter == 0 && getFirstChar(input) != '2') {
            if (getFirstChar(input) == '1') {
                source = getString(input);
            }
            else {
                cout << "Choice can be 1, 2 or 3! Try again." << endl;
            }
        }
        if (getFirstChar(input) == '1' && sourceInputCheck(source) == true) {
            cout << "Source word has been changed to " << "\"" << source << "\"";
            cout << endl;
            counter++;
        }
        else if (getFirstChar(input) == '1' && sourceInputCheck(source) == false) {
            cout << "Wrong input format! Try again." << endl;
        }
        else if ((getFirstChar(input) == '2' && counter == 0)) {
            cout << "Wrong input format! Try again." << endl;
            counter = 0;
        }
        else if (getFirstChar(input) == '2' && searchInputCheck(search) == true && counter != 0 && stringLengthComparison(source, search) == 1) {
            int z = 0;
                for (int i = 0; i < source.length(); i++) {
                    char ch1 = source.at(i);
                    char ch2 = search.at(0);
                    x = i;
                    y = 0;
                    develop = 0;
                    while (ch1 == ch2 || ch2 == '?') {
                        develop++;
                        x++;
                        y++;
                        if (x < source.length()) {
                            ch1 = source.at(x);
                        }
                        ch2 = search.at(y);
                        if (develop == search.length() - 1 && (ch2 == ch1 || ch2 == '?' )) {
                            newSearch = source.substr(i, search.length());
                            if (search.length() == newSearch.length()) {
                                if (z == 0) {
                                    cout << "For the source word " << "\"" << source << "\"" << " and search word " << "\"" << search << "\"," << endl;
                                    z = 1;
                                }
                                if (z == 1) {
                                    if (ch1 == ch2 || ch2 == '?') {
                                        cout << "\"" << newSearch << "\"" << " has been found at index " << i << endl;
                                    }
                                }
                            }
                        }
                        if (y == (search.length()-1) || x == (source.length()-1)) {
                            ch2 = '-';
                        }
                    }
                    if (doNotContain(source, search) && doNotContain(search, "?")) {
                        cout << "For the source word " << "\"" << source << "\"" << " and search word " << "\"" << search << "\", no match has been found." << endl;
                        i = int(source.length());
                    }
                }
        }
        else if ((getFirstChar(input) == '1' || getFirstChar(input) == '2' || getFirstChar(input) == '3') && stringLengthComparison(source, search) == 0) {
            cout << "Wrong input format! Try again." << endl;
        }
            
        cout << endl;
    }
    return 0;
}
