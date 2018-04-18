#include <bits/stdc++.h>

using namespace std;

int main() {
	int M, N;
	map<string, double> dic;
	
	cin >> M >> N;
	
	while(M--) {
		char p[18];
		string str;
		double v;
		
		scanf("%s", p);
		str = p;
		
		cin >> v;
		
		dic.insert(pair<string, double>(str, v));
	}
	
	while(N--) {
		char p[18];
		double sum = 0;
		vector<string> desc;
		string tdesc;
		
		desc.clear();
		
		scanf("%s", p);
		tdesc = p;
		while(tdesc != ".") {
			desc.push_back(tdesc);
			scanf("%s", p);
			tdesc = p;
		}
		
		for(int i = 0; i < desc.size(); i++) {
			sum += dic[desc.at(i)];
		}
		
		printf("%.0lf\n", sum);
	}
	
	return 0;
}