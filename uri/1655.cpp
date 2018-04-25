#include <bits/stdc++.h>
#define MAX 101
using namespace std;

map<int, vector<pair<int, double> > > graph; // u -> {v, custo}
double d[MAX] = {1};

double dijkstra(int s, int f) {
    queue<int> q;

    d[s] = 0;
    q.push(s);

    while(!q.empty()) {
        int atual = q.front();
        q.pop();

        int n_filhos = graph[atual].size();

        for(int i = 0; i < n_filhos; i++) {

            int filho = graph[atual][i].first;
            double custo_atual_filho = graph[atual][filho].second;

            if(d[filho] < d[atual] * custo_atual_filho) {
                d[filho] = d[atual] * custo_atual_filho;

                printf("Custo de %d a %d = %lf\n", s, filho, d[filho]);

                q.push(filho);
            }

        }
    }

    return d[f];
}

int main() {
    int n, m;

    cin >> n;
    while(n > 0) {
        cin >> m;

        int s = -1, f;

        while(m--) {
            int a, b;
            double p;

            cin >> a >> b >> p;
            graph[a].push_back({b, p/100.0});
            graph[b].push_back({a, p/100.0});

            if(s == -1) s = a;
            else if(m == 1) f = b;
        }

        printf("%.6lf percent\n", dijkstra(s, f));

        cin >> n;
    }

    return 0;
}