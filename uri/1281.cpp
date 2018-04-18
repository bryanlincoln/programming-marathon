#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, M, P;
	map<string, double> produtos;
	double preco;
	
	cin >> N;
	
	while(N--) {
		cin >> M;
		produtos.clear();
		while(M--) {
			double value;
			char tstr[60];
			string str;
			
			scanf("%s", tstr);
			str = tstr;
			cin >> value;
			
			produtos.insert(pair<string, double>(str, value));
		}
		
		cin >> P;
		preco = 0;
		while(P--) {
			int qtd;
			char tstr[60];
			string str;
			
			scanf("%s", tstr);
			str = tstr;
			
			cin >> qtd;
				
			preco += qtd * produtos[str];
		}
		
		printf("R$ %.2lf\n", preco);
	}
	
	return 0;
}