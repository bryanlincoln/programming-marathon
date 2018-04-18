#include <bits/stdc++.h>

using namespace std;

typedef struct _Atendente {
	int id;
	int ocupado;
	int custo;
} Atendente;


bool operator<(Atendente p1, Atendente p2) {
	if(p1.ocupado == p2.ocupado) {
		return p1.id > p2.id;	
	}

	return p1.ocupado > p2.ocupado;
}

int main() {
	unsigned long N, M, tempo = 0, c;
	priority_queue<Atendente> atendente;
	Atendente a;

	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	a.ocupado = 0;
	for(int i = 0; i < N; i++) {
		a.id = i;
		cin >> a.custo;
		atendente.push(a);
	}
	
	while(M--) {
		cin >> c;
		a = atendente.top();
		atendente.pop();
		a.ocupado += a.custo * c;
		if(a.ocupado > tempo) {
			tempo = a.ocupado;
		}
		
		atendente.push(a);
	}
	
	cout << tempo << endl;
	
	return 0;
}