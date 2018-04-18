#include <bits/stdc++.h>

using namespace std;

int main() {
    string tempphrase;
    
    getline(cin, tempphrase);

    while(tempphrase != ".") {
        map<string, int> charsum;
        map<char, string> abreviadas;
        string tempword;
        istringstream phrase(tempphrase);
        istringstream outphrase(tempphrase);
        
        while(phrase >> tempword) {
            charsum[tempword] += tempword.size() - 2;
            if(tempword.size() > 2 && charsum[tempword] > charsum[abreviadas[tempword[0]]]) {
                abreviadas[tempword[0]] = tempword;
            }
        }
        
        while(outphrase >> tempword) {
            if(tempword.size() > 2 && abreviadas[tempword[0]] == tempword)
                cout << tempword[0] << ".";
            else
                cout << tempword;
            
            if(outphrase.rdbuf()->in_avail() != 0)
                cout << " ";
        }
        cout << endl << abreviadas.size() << endl;
        
        for(map<char, string>::iterator it = abreviadas.begin(); it != abreviadas.end(); it++) {
                cout << it->first << ". = " << it->second << endl;
        }
        
        getline(cin, tempphrase);
    }
    
    return 0;
}