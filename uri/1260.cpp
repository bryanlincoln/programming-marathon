#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string temp;
    
    cin >> N;
    
    getline(cin, temp);
    getline(cin, temp);
    
    while(N--) {
        map<string, double> populacao;
        double total = 0;
        
        while(getline(cin, temp) && !temp.empty()) {
            populacao[temp] += 1;
            total++;
        }
        
        for(map<string, double>::iterator it = populacao.begin(); it != populacao.end(); it++) {
            printf("%s %.4lf\n", it->first.c_str(), (it->second / total) * 100);
        }
        
        if(N > 0) cout << endl;
    }
    
    return 0;
}