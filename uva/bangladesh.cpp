#include <bits/stdc++.h>

using namespace std;

class Compare {
public:
    bool operator() (pair<pair<unsigned long long, unsigned long long>, unsigned long long> A, pair<pair<unsigned long long, unsigned long long>, unsigned long long> B) {
        return A.first.first > B.first.first || (A.first.first == B.first.first && A.first.second > B.first.second);
    }
};

int main() {
    unsigned long long n;
    bool first = true;
    scanf("%llu", &n);

    while(n--) {
        if(first) first = false;
        else cout << endl;

        unsigned long long x, y;
        map<unsigned long long, vector< pair<unsigned long long, pair<unsigned long long, unsigned long long> > > > graph; // nó - lista (viz, {tempo, distancia})
        scanf("%llu %llu", &x, &y);
        
        while(y--) {
            unsigned long long a, b, c, d;
            scanf("%llu %llu %llu %llu", &a, &b, &c, &d);
            
            graph[a].push_back({b, {c, d}});
            graph[b].push_back({a, {c, d}});
        }

        unsigned long long q;
        scanf("%llu", &q);

        while(q--) {
            unsigned long long s, t;
            scanf("%llu %llu", &s, &t);
            
            vector<bool> vis;
            vector<pair<unsigned long long, unsigned long long> > dist;
            priority_queue<
                pair<pair<unsigned long long, unsigned long long>, unsigned long long>, 
                vector<pair<pair<unsigned long long, unsigned long long>, unsigned long long> >, 
                Compare 
            > que;

            vis.resize(x + 1, false);
            dist.resize(x + 1, {INT_MAX, INT_MAX});
            que.push({{0, 0}, s});
            dist[s] = {0, 0};
            
            while(!que.empty()) {
                unsigned long long atual = que.top().second;
                pair<unsigned long long, unsigned long long> acost = que.top().first;
                que.pop();

                if(vis[atual]) continue;
                
                for(unsigned long long i = 0; i < graph[atual].size(); i++) {
                    unsigned long long vizinho = graph[atual].at(i).first;
                    pair<unsigned long long, unsigned long long> cost = graph[atual].at(i).second;
                    
                    if(vis[vizinho]) continue;

                    if(dist[vizinho].first > acost.first + cost.first ||
                       (dist[vizinho].first == acost.first + cost.first && 
                        dist[vizinho].second > acost.second + cost.second)) {
                        dist[vizinho] = {acost.first + cost.first, acost.second + cost.second};
                        que.push({dist[vizinho], vizinho});
                    }
                }

                vis[atual] = true;
            }

            if(dist[t].second < 1e9)
                cout << "Distance and time to reach destination is " << dist[t].second << " & " << dist[t].first << "." << endl;
            else
                cout << "No Path." << endl;
        }
    }

    return 0;
}