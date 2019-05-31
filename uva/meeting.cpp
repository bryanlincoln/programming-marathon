#include <bits/stdc++.h>

using namespace std;

map<char, int> * dijkstra(map< char, vector< pair< char, int > > > * graph, char s, map< char, bool > * c) {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > que;
    map<char, bool> vis;
    map<char, int> * dist = new map<char, int>();

    for(auto it = c->begin(); it != c->end(); it++) (*dist)[(*it).first] = 1e9;
    (*dist)[s] = 0;
    que.push({0, s});

    while(!que.empty()) {
        int atual = que.top().second;
        que.pop();

        if(vis[atual]) continue;
        vis[atual] = true;

        for(int i = 0; i < (*graph)[atual].size(); i++) {
            int vizinho = (*graph)[atual].at(i).first;
            int cost = (*graph)[atual].at(i).second;

            if((*dist)[vizinho] > (*dist)[atual] + cost) {
                (*dist)[vizinho] = (*dist)[atual] + cost;
                que.push({(*dist)[vizinho], vizinho});
            }
        }
    }

    return dist;
}

int main() {
    int n;

    while(cin >> n && n) {
        map< char, vector< pair< char, int > > > young, elder; // from -> [to, cost]
        map< char, bool > c;

        for(int sd = 0; sd < n; sd++) {
            char res, direction, x, y;
            int cost;

            cin >> res >> direction >> x >> y >> cost;

            c[x] = true;
            c[y] = true;

            if(res == 'Y') { // young
                young[x].push_back({y, cost});
                if(direction == 'B') young[y].push_back({x, cost});
            } else { // elder
                elder[x].push_back({y, cost});
                if(direction == 'B') elder[y].push_back({x, cost});
            }
        }

        char s1, s2;
        cin >> s1 >> s2;

        map<char, int> * dist1 = dijkstra(&young, s1, &c);
        map<char, int> * dist2 = dijkstra(&elder, s2, &c);

        int min = 1e9;
        map<int, vector<char>> mincs;
        for(auto it = c.begin(); it != c.end(); it++) {
            char C = it->first;
            if((*dist1)[C] + (*dist2)[C] <= min) {
                min = (*dist1)[C] + (*dist2)[C];
                mincs[min].push_back(C);
            }
        }
        sort(mincs[min].begin(), mincs[min].end());

        if(min < 1e9) {
            cout << min;
            for(int i = 0; i < mincs[min].size(); i++) {
                cout << " " << mincs[min][i];
            }
            cout << endl;
        }
        else if(s1 == s2) {
            cout << "0 " << s1 << endl;
        }
        else cout << "You will never meet." << endl;
    }

    return 0;
}