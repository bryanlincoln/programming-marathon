#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    
    cin >> N;
    
    while(N > 0) {
        list<int> deck;
        for(int i = 1; i <= N; i++) {
            deck.push_front(i);
        }
        
        cout << "Discarded cards: ";
        
        while(N > 1) {
            cout << deck.back() << (N > 2 ? ", " : "");
            
            deck.pop_back();
            deck.push_front(deck.back());
            deck.pop_back();
            
            N--;
        }
        
        cout << "\nRemaining card: " << deck.front() << endl;
    
        cin >> N;
    }
    
    return 0;
}