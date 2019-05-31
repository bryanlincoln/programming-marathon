#include <bits/stdc++.h>

using namespace std;

typedef struct _Hero {
    string name;
    int a, v, s;
} Hero;

int main() {
    int n;
    vector<Hero> heros;

    cin >> n;

    while(n--) {
        string name;
        int a, v, s;
        Hero hero;

        cin >> name >> a >> v >> s;

        hero.name = name;
        hero.a = a;
        hero.v = v;
        hero.s = s;

        heros.push_back(hero);
    }

    sort(heros.begin(), heros.end(), [](const Hero& h1, const Hero& h2) {
        if(h1.a != h2.a) return h1.a > h2.a;
        else if(h1.v != h2.v) return h1.v > h2.v;
        else if(h1.s != h2.s) return h1.s < h2.s;
        else return h1.name.compare(h2.name) < 0;
    });

    for(int i = 0; i < heros.size(); i++) {
        cout << heros[i].name << endl;
    }

    return 0;
}