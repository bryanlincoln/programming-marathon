#include <bits/stdc++.h>

using namespace std;

char tolower(char c) {
    if(c >= 'A' && c <= 'Z')
        return c + 32;
    return c;
}

int main() {
    string word;

    cin >> word;

    for(int i = 0; i < word.length(); i++) {
        char letter = tolower(word[i]);
        if(letter != 'a' && letter != 'e' && letter != 'i' && letter != 'o' && letter != 'u' && letter != 'y')
            cout << "." << letter;
    }

    cout << endl;

    return 0;
}